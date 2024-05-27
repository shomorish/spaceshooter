#include "title.h"

#include "../animation/ease_in_out_sine.h"
#include "../input/im_menu.h"

namespace spaceshooter {

Title::Title(GameContext* game_context, OpenLevelInterface* open_level_interface)
    : Level{game_context, open_level_interface}, state_(TitleState::kEnter),
      enter_text_animation_(NULL) {
    set_input_mapping(new IM_Menu());

    door_.Init(
        [this]() {
            state_ = TitleState::kPlay;
            door_.ResetOpenAnimation();
        },
        [this]() { open_level_interface_->OpenLevel(LevelType::kStage1); });

    // タイトルを設定
    title_text_view_.set_window(game_context_->get_window());
    title_text_view_.SetAnchor(Anchor::kTopCenter);
    title_text_view_.SetPivot(Pivot::kTopCenter);
    title_text_view_.SetPos(Vector2{0.f, 80.f});
    title_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 80);
    title_text_view_.SetVViewType(ViewType::kWrapContent);
    title_text_view_.SetHViewType(ViewType::kWrapContent);
    title_text_view_.SetText("SPACE SHOOTER", SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                             game_context_->get_renderer()->sdl());

    // 入力を促すメッセージの設定
    enter_text_view_.set_window(game_context_->get_window());
    enter_text_view_.SetAnchor(Anchor::kBottomCenter);
    enter_text_view_.SetPivot(Pivot::kBottomCenter);
    enter_text_view_.SetPos(Vector2{0.f, -80.f});
    enter_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 24);
    enter_text_view_.SetVViewType(ViewType::kWrapContent);
    enter_text_view_.SetHViewType(ViewType::kWrapContent);
    enter_text_view_.SetText("PRESS THE \"ENTER\" TO START THE GAME",
                             SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                             game_context_->get_renderer()->sdl());
    enter_text_view_.SetAlpha(0); // 最初は透明に設定
    enter_text_animation_ = new InfinityAnimation(
        new EaseInOutSine(),
        [this](float value) {
            Uint8 alpha = (Uint8)(0xFF * value);
            enter_text_view_.SetAlpha(alpha);
        },
        1.f);
}

Title::~Title() {
    if (enter_text_animation_) {
        delete enter_text_animation_;
        enter_text_animation_ = NULL;
    }
}

void Title::Tick(float delta_time) {
    switch (state_) {
    case TitleState::kEnter:
        door_.OpenTick(delta_time);
        break;
    case TitleState::kExit:
        door_.CloseTick(delta_time);
        break;
    case TitleState::kPlay:
        enter_text_animation_->Tick(delta_time);
        const InputActionContainer* action_container = GetInputActionContainer();
        auto decision = action_container->GetActionOrNull(InputActionType::kDecision);
        if (decision) {
            state_ = TitleState::kExit;
        }
        break;
    }
}

void Title::Render() {
    auto renderer = game_context_->get_renderer()->sdl();
    title_text_view_.Render(renderer);
    enter_text_view_.Render(renderer);

    /**
     * オーバーレイの描画
     */
    switch (state_) {
    case TitleState::kEnter:
    case TitleState::kExit:
        door_.Render(renderer);
        break;
    }
}

} // namespace spaceshooter