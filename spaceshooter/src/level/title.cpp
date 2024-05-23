#include "title.h"

namespace spaceshooter {

Title::Title(GameContext* game_context) : Level{game_context} {
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
}

Title::~Title() {}

void Title::Tick(std::vector<InputAction> actions, float delta_time) {}

void Title::Render() {
    auto renderer = game_context_->get_renderer()->sdl();
    title_text_view_.Render(renderer);
    enter_text_view_.Render(renderer);
}

} // namespace spaceshooter