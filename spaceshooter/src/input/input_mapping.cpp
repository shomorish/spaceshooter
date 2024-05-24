#include "input_mapping.h"

namespace spaceshooter {

InputMapping::InputMapping() : key_state_{0}, mouse_button_state_{0} {}

InputMapping::~InputMapping() {}

void InputMapping::HandleInputEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        int scancode = event.key.keysym.scancode;
        if (scancode < kKeyNum && key_state_[scancode] == 0) {
            key_state_[scancode] = 1;
        }
    } else if (event.type == SDL_KEYUP) {
        int scancode = event.key.keysym.scancode;
        if (scancode < kKeyNum) {
            key_state_[scancode] = 0;
        }
    } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        if (mouse_button_state_[SDL_BUTTON_LEFT] == 0) {
            mouse_button_state_[SDL_BUTTON_LEFT] = 1;
        }
    } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
        mouse_button_state_[SDL_BUTTON_LEFT] = 0;
    } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT) {
        if (mouse_button_state_[SDL_BUTTON_RIGHT] == 0) {
            mouse_button_state_[SDL_BUTTON_RIGHT] = 1;
        }
    } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT) {
        mouse_button_state_[SDL_BUTTON_RIGHT] = 0;
    }
}

void InputMapping::UpdateInputState() {
    // キーの長押し判定の為に、キーが入力されている場合は入力状態の値をインクリメント
    for (int i = 0; i < kKeyNum; i++) {
        // key_state_の要素はUint8なので、255以上だったらインクリメントしない
        if (key_state_[i] > 0 && key_state_[i] < 255) {
            key_state_[i]++;
        }
    }

    for (int i = 0; i < kMouseButtonNum; i++) {
        if (mouse_button_state_[i] > 0 && mouse_button_state_[i] < 255) {
            mouse_button_state_[i]++;
        }
    }
}

void InputMapping::ClearInputActions() { action_container_.Clear(); }

} // namespace spaceshooter