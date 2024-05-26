#include "pause_menu.h"

#include "../animation/ease_in_out_sine.h"

namespace spaceshooter {

PauseMenu::PauseMenu()
    : is_open_(false), animation_state_(PauseMenuAnimationState::kNone),
      cursor_(PauseMenuItem::kNo) {

    open_animation_ = new FiniteAnimation(new EaseInOutSine(), [this](float value) {
        Uint8 alpha = (Uint8)(0xFF * value);
        frame_image_view_.SetAlpha(alpha);
        cursor_image_view_.SetAlpha(alpha);
        message_text_view_.SetAlpha(alpha);
        yes_text_view_.SetAlpha(alpha);
        no_text_view_.SetAlpha(alpha);
    });
    open_animation_->RegistOnCompleteListener([this]() {
        animation_state_ = PauseMenuAnimationState::kNone;
        open_animation_->Reset();
    });

    close_animation_ = new FiniteAnimation(
        new EaseInOutSine(),
        [this](float value) {
            Uint8 alpha = (Uint8)(0xFF * value);
            frame_image_view_.SetAlpha(alpha);
            cursor_image_view_.SetAlpha(alpha);
            message_text_view_.SetAlpha(alpha);
            yes_text_view_.SetAlpha(alpha);
            no_text_view_.SetAlpha(alpha);
        },
        1.f, 1.f);
    close_animation_->RegistOnCompleteListener([this]() {
        animation_state_ = PauseMenuAnimationState::kNone;
        close_animation_->Reset();
    });
}

PauseMenu::~PauseMenu() {
    if (open_animation_) {
        open_animation_->UnregistOnCompleteListener();
        delete open_animation_;
        open_animation_ = NULL;
    }

    if (close_animation_) {
        close_animation_->UnregistOnCompleteListener();
        delete close_animation_;
        close_animation_ = NULL;
    }
}

void PauseMenu::Init(Texture* pause_menu_texture, Texture* cursor_texture, Window* window,
                     SDL_Renderer* renderer) {
    frame_image_view_.SetImage(pause_menu_texture);
    frame_image_view_.SetAnchor(Anchor::kCenterCenter);
    frame_image_view_.SetPivot(Pivot::kCenterCenter);
    frame_image_view_.SetSize(Vector2{600.f, 280.f});
    frame_image_view_.set_window(window);
    frame_image_view_.SetAlpha(0);

    cursor_image_view_.SetImage(cursor_texture);
    cursor_image_view_.SetAnchor(Anchor::kCenterCenter);
    cursor_image_view_.SetPivot(Pivot::kCenterCenter);
    cursor_image_view_.SetSize(Vector2{24.f, 24.f});
    cursor_image_view_.set_window(window);
    cursor_image_view_.SetAlpha(0);

    message_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 24);
    message_text_view_.SetText("Back to the title?", SDL_Color{0xFF, 0xFF, 0xFF, 0xFF}, renderer);
    message_text_view_.SetHViewType(ViewType::kWrapContent);
    message_text_view_.SetVViewType(ViewType::kWrapContent);
    message_text_view_.SetAnchor(Anchor::kCenterCenter);
    message_text_view_.SetPivot(Pivot::kCenterCenter);
    message_text_view_.SetPos(Vector2{0.f, -40.f});
    message_text_view_.SetAlpha(0);
    message_text_view_.set_window(window);

    no_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 24);
    no_text_view_.SetText("NO", SDL_Color{0xFF, 0xFF, 0xFF, 0xFF}, renderer);
    no_text_view_.SetHViewType(ViewType::kWrapContent);
    no_text_view_.SetVViewType(ViewType::kWrapContent);
    no_text_view_.SetAnchor(Anchor::kCenterCenter);
    no_text_view_.SetPivot(Pivot::kCenterRight);
    no_text_view_.SetPos(Vector2{-40.f, 40.f});
    no_text_view_.SetAlpha(0);
    no_text_view_.set_window(window);

    yes_text_view_.set_font("assets/fonts/PixelifySans-Bold.ttf", 24);
    yes_text_view_.SetText("YES", SDL_Color{0xFF, 0xFF, 0xFF, 0xFF}, renderer);
    yes_text_view_.SetHViewType(ViewType::kWrapContent);
    yes_text_view_.SetVViewType(ViewType::kWrapContent);
    yes_text_view_.SetAnchor(Anchor::kCenterCenter);
    yes_text_view_.SetPivot(Pivot::kCenterLeft);
    yes_text_view_.SetPos(Vector2{40.f, 40.f});
    yes_text_view_.SetAlpha(0);
    yes_text_view_.set_window(window);
}

void PauseMenu::Open() {
    animation_state_ = PauseMenuAnimationState::kOpen;
    is_open_ = true;
}

void PauseMenu::Close() {
    animation_state_ = PauseMenuAnimationState::kClose;
    is_open_ = false;
}

void PauseMenu::MoveCursorUp() {
    int cursor = (int)cursor_ - 1;
    if (cursor < (int)PauseMenuItem::kNo) {
        cursor_ = PauseMenuItem::kYes;
    } else {
        cursor_ = (PauseMenuItem)cursor;
    }
}

void PauseMenu::MoveCursourDown() {
    int cursor = (int)cursor_ + 1;
    if (cursor > (int)PauseMenuItem::kYes) {
        cursor_ = PauseMenuItem::kNo;
    } else {
        cursor_ = (PauseMenuItem)cursor;
    }
}

PauseMenuItem PauseMenu::Determine() { return cursor_; }

void PauseMenu::Render(SDL_Renderer* renderer) {
    frame_image_view_.Render(renderer);
    switch (cursor_) {
    case PauseMenuItem::kNo:
        cursor_image_view_.SetPos(Vector2{-100.f, 40.f});
        break;
    case PauseMenuItem::kYes:
        cursor_image_view_.SetPos(Vector2{10.f, 40.f});
        break;
    }
    cursor_image_view_.Render(renderer);
    message_text_view_.Render(renderer);
    no_text_view_.Render(renderer);
    yes_text_view_.Render(renderer);
}

bool PauseMenu::IsOpen() { return is_open_; }

bool PauseMenu::IsDuringAnimation() { return animation_state_ != PauseMenuAnimationState::kNone; }

void PauseMenu::Animation(const float& delta_time) {
    if (animation_state_ == PauseMenuAnimationState::kOpen) {
        open_animation_->Tick(delta_time);
    } else if (animation_state_ == PauseMenuAnimationState::kClose) {
        close_animation_->Tick(delta_time);
    }
}

} // namespace spaceshooter