#include "stage1.h"

#include <random>

#include "../actor/alien.h"
#include "../actor/asteroid.h"
#include "../actor/background.h"
#include "../actor/rush_ai_spawner.h"
#include "../actor/straight_bullet.h"
#include "../collision/linear_quadtree.h"
#include "../input/im_menu.h"
#include "../input/im_playing.h"

namespace spaceshooter {

static const Range AREA_X_RANGE = Range{0.f, 1600.f};
static const Range AREA_Y_RANGE = Range{0.f, 1600.f};

Stage1::Stage1(GameContext* game_context, OpenLevelInterface* open_level_interface)
    : Level{game_context, open_level_interface}, state_(Stage1State::kEnter),
      player_controller_(NULL) {

    set_input_mapping(new IM_Playing());

    door_.Init([this]() { state_ = Stage1State::kIntro; },
               [this]() { state_ = Stage1State::kExited; });

    camera_.Init(AREA_X_RANGE, AREA_Y_RANGE, game_context_->get_window());

    AddActor(new Background(game_context_->get_asset_manager()->GetTexture(AssetKey::kBackground),
                            Vector2{-800.f, -600.f}, Vector2{1024.f * 4.f, 512.f * 4.f}));

    AddActor(new PlayerController(this, AREA_X_RANGE, AREA_Y_RANGE));
    player_controller_ = (PlayerController*)actors_.back();
    auto player = new Player(player_controller_, get_asset_manager()->GetTexture(AssetKey::kShip1),
                             Vector2{AREA_X_RANGE.max / 2.f, AREA_Y_RANGE.max / 2.f});
    player_controller_->Attach(player);
    AddActor(player);

    quadtree_.Init(3, Vector2::zero, Vector2{AREA_X_RANGE.max, AREA_Y_RANGE.max});
    collision_list_ = NULL;

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    for (int i = 0; i < 20; i++) {
        float scale = std::uniform_real_distribution<float>(1.f, 2.5f)(engine);
        Vector2 size = Vector2{30.f, 30.f} * scale;

        Vector2 pos = Vector2{std::uniform_real_distribution<float>(0.f, 1600.f - size.x)(engine),
                              std::uniform_real_distribution<float>(0.f, 1600.f - size.y)(engine)};

        Texture* texture = game_context_->get_asset_manager()->GetTexture(AssetKey::kAsteroid);

        float angle = 0.f;

        float rotation_speed = std::uniform_real_distribution<float>(-180.f, 180.f)(engine);

        AddActor(new Asteroid(texture, pos, size, angle, rotation_speed));
    }

    enemy_counter_.max_spawn_enemies = 30;
    enemy_counter_.num_of_spawned_enemies = 0;
    enemy_counter_.num_of_destroy_enemies = 0;
    AddActor(new RushAiSpawner(this, Vector2{100.f, 100.f}, 5.f,
                               player_controller_->GetCharacterRef(), &enemy_counter_));
    AddActor(new RushAiSpawner(this, Vector2{AREA_X_RANGE.max - 100.f, 100.f}, 8.f,
                               player_controller_->GetCharacterRef(), &enemy_counter_));
    AddActor(new RushAiSpawner(this, Vector2{AREA_X_RANGE.max / 2.f, AREA_Y_RANGE.max - 100.f},
                               10.f, player_controller_->GetCharacterRef(), &enemy_counter_));

    enemies_text_view_.set_window(game_context_->get_window());
    enemies_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 20);
    enemies_text_view_.SetHViewType(ViewType::kWrapContent);
    enemies_text_view_.SetVViewType(ViewType::kWrapContent);
    enemies_text_view_.SetAnchor(Anchor::kTopCenter);
    enemies_text_view_.SetPivot(Pivot::kTopCenter);
    enemies_text_view_.SetPos(Vector2{0.f, 10.f});

    score_text_view_.set_window(game_context_->get_window());
    score_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 20);
    score_text_view_.SetHViewType(ViewType::kWrapContent);
    score_text_view_.SetVViewType(ViewType::kWrapContent);
    score_text_view_.SetAnchor(Anchor::kTopRight);
    score_text_view_.SetPivot(Pivot::kTopRight);
    score_text_view_.SetPos(Vector2{-10.f, 10.f});

    hp_text_view_.set_window(game_context_->get_window());
    hp_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 24);
    hp_text_view_.SetHViewType(ViewType::kWrapContent);
    hp_text_view_.SetVViewType(ViewType::kWrapContent);
    hp_text_view_.SetAnchor(Anchor::kBottomLeft);
    hp_text_view_.SetPivot(Pivot::kBottomLeft);
    hp_text_view_.SetPos(Vector2{24.f, -24.f});

    time_count_text_view_.set_window(game_context_->get_window());
    time_count_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 80);
    time_count_text_view_.SetHViewType(ViewType::kWrapContent);
    time_count_text_view_.SetVViewType(ViewType::kWrapContent);
    time_count_text_view_.SetAnchor(Anchor::kCenterCenter);
    time_count_text_view_.SetPivot(Pivot::kCenterCenter);

    game_clear_text_view_.set_window(game_context_->get_window());
    game_clear_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 80);
    game_clear_text_view_.SetHViewType(ViewType::kWrapContent);
    game_clear_text_view_.SetVViewType(ViewType::kWrapContent);
    game_clear_text_view_.SetAnchor(Anchor::kCenterCenter);
    game_clear_text_view_.SetPivot(Pivot::kCenterCenter);
    game_clear_text_view_.SetText("GAME CLEAR", SDL_Color{0xFF, 0xFF, 0, 0xFF},
                                  game_context_->get_renderer()->sdl());
    game_clear_text_view_.SetAlpha(0);

    game_over_text_view_.set_window(game_context_->get_window());
    game_over_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 80);
    game_over_text_view_.SetHViewType(ViewType::kWrapContent);
    game_over_text_view_.SetVViewType(ViewType::kWrapContent);
    game_over_text_view_.SetAnchor(Anchor::kCenterCenter);
    game_over_text_view_.SetPivot(Pivot::kCenterCenter);
    game_over_text_view_.SetText("GAME OVER", SDL_Color{0xFF, 0, 0, 0xFF},
                                 game_context_->get_renderer()->sdl());
    game_over_text_view_.SetAlpha(0);

    pause_menu_.Init(game_context_->get_asset_manager()->GetTexture(AssetKey::kFrame1),
                     game_context_->get_asset_manager()->GetTexture(AssetKey::kCursor1),
                     game_context_->get_window(), game_context_->get_renderer()->sdl());

    timer_ = 0.f;
}

Stage1::~Stage1() {
    collision_list_ = NULL;

    if (player_controller_ != NULL) {
        player_controller_ = NULL;
    }
}

void Stage1::Tick(float delta_time) {
    switch (state_) {
    case Stage1State::kEnter:
        Enter(delta_time);
        break;
    case Stage1State::kIntro:
        Intro(delta_time);
        break;
    case Stage1State::kPlay:
        Play(delta_time);
        break;
    case Stage1State::kPause:
        Pause(delta_time);
        break;
    case Stage1State::kGameClear:
        GameClear(delta_time);
        break;
    case Stage1State::kGameOver:
        GameOver(delta_time);
        break;
    case Stage1State::kExiting:
        Exiting(delta_time);
        break;
    case Stage1State::kExited:
        open_level_interface_->OpenLevel(LevelType::kTitle);
        break;
    }
}

void Stage1::Render() {
    auto renderer = game_context_->get_renderer()->sdl();
    for (auto iter = actors_.begin(); iter != actors_.end(); iter++) {
        (*iter)->Render(renderer, &camera_);
    }
    enemies_text_view_.Render(renderer);
    score_text_view_.Render(renderer);
    hp_text_view_.Render(renderer);

    switch (state_) {
    case Stage1State::kEnter:
    case Stage1State::kExiting:
    case Stage1State::kExited:
    case Stage1State::kGameClear:
    case Stage1State::kGameOver:
        game_clear_text_view_.Render(renderer);
        game_over_text_view_.Render(renderer);
        door_.Render(renderer);
        break;
    case Stage1State::kPause:
        pause_menu_.Render(renderer);
        break;
    case Stage1State::kIntro:
        time_count_text_view_.Render(renderer);
        break;
    }
}

int Stage1::CalcScore() {
    int score = 0;
    score += enemy_counter_.num_of_destroy_enemies * 100;
    return score;
}

void Stage1::Enter(const float& delta_time) { door_.OpenTick(delta_time); }

void Stage1::Intro(const float& delta_time) {
    timer_ += delta_time;
    if (timer_ >= 3.f) {
        state_ = Stage1State::kPlay;
        timer_ = 0.f;
    }
    time_count_text_view_.SetText(std::to_string((int)(std::ceil(3.f - timer_))),
                                  SDL_Color{0xFF, 0xFF, 0, 0xFF},
                                  game_context_->get_renderer()->sdl());
}

void Stage1::Play(const float& delta_time) {
    /**
     * 残りの敵数の更新
     */
    std::string enemies_text =
        std::to_string(enemy_counter_.max_spawn_enemies - enemy_counter_.num_of_destroy_enemies) +
        '/' + std::to_string(enemy_counter_.max_spawn_enemies);
    enemies_text_view_.SetText(enemies_text, SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                               game_context_->get_renderer()->sdl());

    /**
     * スコアの更新
     */
    std::string score_text = "SCORE: " + std::to_string(CalcScore());
    score_text_view_.SetText(score_text, SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                             game_context_->get_renderer()->sdl());

    /**
     * HPの更新
     */
    int hp = (int)std::ceil(player_controller_->GetPlayerHp());
    std::string hp_bar = "";
    for (int i = 0; i < hp; i++) {
        hp_bar += "[]";
    }
    std::string hp_text = "HP: " + hp_bar;
    hp_text_view_.SetText(hp_text, SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                          game_context_->get_renderer()->sdl());

    /**
     * 削除マークが付いたアクタを削除
     */
    DeleteActorIfDestroyed();

    // TODO:
    // 爆発エフェクト、オーディオ、チュートリアル（or操作方法）
    if (player_controller_->GetPlayerHp() <= 0.f) {
        state_ = Stage1State::kGameOver;
        game_over_text_view_.SetAlpha(0xFF);
        return;
    } else if (enemy_counter_.num_of_destroy_enemies == enemy_counter_.max_spawn_enemies) {
        state_ = Stage1State::kGameClear;
        game_clear_text_view_.SetAlpha(0xFF);
        return;
    }

    /**
     * 衝突判定
     */
    for (auto iter = actors_.begin(); iter != actors_.end(); iter++) {
        if ((*iter)->HasCollider()) {
            // 移動している可能性があるので空間からコライダーを外す
            (*iter)->get_collider()->ExitSpace();
            // 現在地を使用してコライダーを空間に再登録する
            quadtree_.Regist((*iter)->get_collider());
        }
    }
    unsigned int n = quadtree_.GetAllCollisionList(&collision_list_);
    n /= 2; // 衝突リストはペアで登録されているため2で割る
    const std::vector<Collider*>& list = collision_list_->get_collision_list();
    for (unsigned int index = 0; index < n; index++) {
        float r =
            std::pow((list[index * 2]->get_radius() + list[index * 2 + 1]->get_radius()), 2.f);
        float x = (list[index * 2]->GetPos().x - list[index * 2 + 1]->GetPos().x);
        float y = (list[index * 2]->GetPos().y - list[index * 2 + 1]->GetPos().y);
        if (r >= (x * x + y * y)) {
            list[index * 2]->OnCollision(list[index * 2 + 1]->get_actor());
            list[index * 2 + 1]->OnCollision(list[index * 2]->get_actor());
        }
    }

    /**
     * プレイヤー以外の更新処理
     */
    for (int i = 0; i < actors_.size(); i++) {
        actors_[i]->Tick(delta_time);
    }

    const InputActionContainer* action_container = GetInputActionContainer();

    /**
     * プレイヤーの更新処理
     */
    player_controller_->Tick(action_container, delta_time);

    /**
     * ポーズメニュー
     */
    auto pause = action_container->GetActionOrNull(InputActionType::kPause);
    if (pause) {
        state_ = Stage1State::kPause;
        pause_menu_.Open();
        set_input_mapping(new IM_Menu());
    }
}

void Stage1::Pause(const float& delta_time) {
    if (pause_menu_.IsDuringAnimation()) {
        pause_menu_.Animation(delta_time);
    } else {
        if (!pause_menu_.IsOpen()) {
            // ポーズメニューは閉じているのでゲームを再開
            state_ = Stage1State::kPlay;
            set_input_mapping(new IM_Playing());
            return;
        }

        auto action_container = GetInputActionContainer();
        if (action_container->GetActionOrNull(InputActionType::kDecision)) {
            auto menu_item = pause_menu_.Determine();
            if (menu_item == PauseMenuItem::kYes) {
                // タイトルに戻る
                state_ = Stage1State::kExiting;
            } else {
                pause_menu_.Close();
            }
        } else if (action_container->GetActionOrNull(InputActionType::kGoUp)) {
            pause_menu_.MoveCursorUp();
        } else if (action_container->GetActionOrNull(InputActionType::kGoDown)) {
            pause_menu_.MoveCursourDown();
        }
    }
}

void Stage1::GameClear(const float& delta_time) {
    timer_ += delta_time;
    if (timer_ >= 3.f) {
        state_ = Stage1State::kExiting;
        timer_ = 0.f;
    }
}

void Stage1::GameOver(const float& delta_time) {
    timer_ += delta_time;
    if (timer_ >= 3.f) {
        state_ = Stage1State::kExiting;
        timer_ = 0.f;
    }
}

void Stage1::Exiting(const float& delta_time) { door_.CloseTick(delta_time); }

} // namespace spaceshooter