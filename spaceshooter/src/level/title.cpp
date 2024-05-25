#include "title.h"

#include "../animation/ease_in_out_sine.h"
#include "../input/im_menu.h"

namespace spaceshooter {

Title::Title(GameContext* game_context) : Level{game_context}, enter_text_animation_(NULL) {
    set_input_mapping(new IM_Menu());

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
    enter_text_animation_ = new InfinityAnimation(new EaseInOutSine(), [this](float value) {
        Uint8 alpha = (Uint8)(0xFF * std::abs(value));
        enter_text_view_.SetText("PRESS THE \"ENTER\" TO START THE GAME",
                                 SDL_Color{0xFF, 0xFF, 0xFF, alpha},
                                 game_context_->get_renderer()->sdl());
    });
}

Title::~Title() {
    if (enter_text_animation_) {
        delete enter_text_animation_;
        enter_text_animation_ = NULL;
    }
}

void Title::Tick(float delta_time) {
    enter_text_animation_->Tick(delta_time);
    if (get_input_mapping()) {
        const InputActionContainer& action_container = get_input_mapping()->GenerateInputAction();
        auto decision = action_container.GetActionOrNull(InputActionType::kDecision);
        if (decision) {
            printf("kDecision Action\n");
            /*
            TODO: レベル遷移
            画面の暗転アニメーションを開始
            画面の暗転アニメーションが完了
            次のレベルをGameのlevelに設定
            */
        }
    }
}

void Title::Render() {
    auto renderer = game_context_->get_renderer()->sdl();
    title_text_view_.Render(renderer);
    enter_text_view_.Render(renderer);
}

} // namespace spaceshooter