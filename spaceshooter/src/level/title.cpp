#include "title.h"

#include "../animation/ease_in_out_sine.h"

namespace spaceshooter {

Title::Title(GameContext* game_context) : Level{game_context}, enter_text_animation_(NULL) {
    // TODO: Change input mapping.
    game_context_->set_input_mapping(NULL);

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
    enter_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 20);
    enter_text_view_.SetVViewType(ViewType::kWrapContent);
    enter_text_view_.SetHViewType(ViewType::kWrapContent);
    enter_text_view_.SetText("PLEASE ENTER ANY KEY", SDL_Color{0xFF, 0xFF, 0xFF, 0xFF},
                             game_context_->get_renderer()->sdl());

    enter_text_animation_ = new InfinityAnimation(new EaseInOutSine(), [this](float value) {
        Uint8 alpha = (Uint8)(0xFF * std::abs(value));
        enter_text_view_.SetText("PLEASE ENTER ANY KEY", SDL_Color{0xFF, 0xFF, 0xFF, alpha},
                                 game_context_->get_renderer()->sdl());
    });
}

Title::~Title() {
    if (enter_text_animation_) {
        delete enter_text_animation_;
        enter_text_animation_ = NULL;
    }
}

void Title::Tick(std::vector<InputAction> actions, float delta_time) {
    enter_text_animation_->Tick(delta_time);
}

void Title::Render() {
    auto renderer = game_context_->get_renderer()->sdl();
    title_text_view_.Render(renderer);
    enter_text_view_.Render(renderer);
}

} // namespace spaceshooter