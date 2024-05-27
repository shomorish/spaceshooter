#include "explosion.h"

namespace spaceshooter {

Explosion::Explosion(Vector2 pos, Vector2 size, SpriteSheetTexture* texture) {
    pos_ = pos;
    size_ = size;
    texture_ = texture;
    sprite_index_ = 0;
    update_duration_ = 0.03f;
    elapsed_time_ = 0.f;
}

Explosion::~Explosion() { texture_ = NULL; }

void Explosion::Tick(const float& delta_time) {
    elapsed_time_ += delta_time;
    sprite_index_ = (int)(elapsed_time_ / update_duration_);
    // スプライトの数を超えたら削除
    if (sprite_index_ >= texture_->get_num_of_sprites()) {
        Destroy();
    }
}

void Explosion::Render(SDL_Renderer* renderer, Camera* camera) {
    if (is_destroyed_) return;
    Vector2 pos;
    bool result = camera->ConvertToWindowCoords(pos_, &pos);
    if (result) {
        Vector2 pos_with_offset{pos.x - size_.x / 2.f, pos.y - size_.y / 2.f};
        texture_->Render(renderer, sprite_index_, pos_with_offset, &size_);
    }
}

} // namespace spaceshooter