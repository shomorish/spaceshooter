#include "text_view.h"

namespace spaceshooter {

TextView::TextView() : view_info_(ViewInfo()), font_(NULL), texture_(NULL), window_(NULL) {}

TextView::TextView(Window* window, ViewInfo view_info, std::string font_path, int point_size)
    : view_info_(view_info), font_(NULL), texture_(NULL), window_(window) {

    if (!font_path.empty() && point_size != 0) {
        set_font(font_path, point_size);
    }
}

TextView::~TextView() {
    window_ = NULL;

    if (font_) {
        delete font_;
        font_ = NULL;
    }

    if (texture_) {
        delete texture_;
        texture_ = NULL;
    }
}

void TextView::set_font(std::string path, int point_size) { font_ = new Font(path, point_size); }

void TextView::set_window(Window* window) { window_ = window; }

void TextView::SetText(std::string text, SDL_Color text_color, SDL_Renderer* renderer) {
    if (font_) {
        if (texture_) {
            delete texture_;
            texture_ = NULL;
        }
        texture_ = new Texture(font_, text, text_color, renderer);
    }
}

void TextView::SetPos(Vector2 pos) { view_info_.pos = pos; }

void TextView::SetSize(Vector2 size) { view_info_.size = size; }

void TextView::SetHViewType(ViewType view_type) { view_info_.h_view_type = view_type; }

void TextView::SetVViewType(ViewType view_type) { view_info_.v_view_type = view_type; }

void TextView::SetAnchor(Anchor anchor) { view_info_.anchor = anchor; }

void TextView::SetPivot(Pivot pivot) { view_info_.pivot = pivot; }

void TextView::Render(SDL_Renderer* renderer) {
    if (window_ == NULL) return;

    if (texture_) {
        float pos_x = view_info_.pos.x;
        float pos_y = view_info_.pos.y;
        float size_w = view_info_.size.x;
        float size_h = view_info_.size.y;

        switch (view_info_.h_view_type) {
        case kWrapContent:
            size_w = texture_->get_width();
        }

        switch (view_info_.v_view_type) {
        case kWrapContent:
            size_h = texture_->get_height();
        }

        /**
         * アンカーの座標を計算
         */
        float anchor_pos_x = 0.f;
        float anchor_pos_y = 0.f;

        int anchor_h = view_info_.anchor & MASK_V;
        if (anchor_h == ANCHOR_PIVOT_H_CENTER) {
            anchor_pos_x = window_->get_width() / 2.f;
        } else if (anchor_h == ANCHOR_PIVOT_RIGHT) {
            anchor_pos_x = (float)window_->get_width();
        }

        int anchor_v = view_info_.anchor & MASK_H;
        if (anchor_v == ANCHOR_PIVOT_V_CENTER) {
            anchor_pos_y = window_->get_height() / 2.f;
        } else if (anchor_v == ANCHOR_PIVOT_BOTTOM) {
            anchor_pos_y = (float)window_->get_height();
        }

        /**
         * ビューの座標を計算
         */
        float pivot_pos_x = anchor_pos_x + pos_x;
        float pivot_pos_y = anchor_pos_y + pos_y;

        int pivot_h = view_info_.pivot & MASK_V;
        if (pivot_h == ANCHOR_PIVOT_H_CENTER) {
            pos_x = pivot_pos_x - (size_w / 2.f);
        } else if (pivot_h == ANCHOR_PIVOT_RIGHT) {
            pos_x = pivot_pos_x - size_w;
        } else {
            pos_x = pivot_pos_x;
        }

        int pivot_v = view_info_.pivot & MASK_H;
        if (pivot_v == ANCHOR_PIVOT_V_CENTER) {
            pos_y = pivot_pos_y - (size_h / 2.f);
        } else if (pivot_v == ANCHOR_PIVOT_BOTTOM) {
            pos_y = pivot_pos_y - size_h;
        } else {
            pos_y = pivot_pos_y;
        }

        SDL_FRect rect{pos_x, pos_y, size_w, size_h};
        SDL_RenderCopyF(renderer, texture_->sdl(), NULL, &rect);
    }
}

} // namespace spaceshooter