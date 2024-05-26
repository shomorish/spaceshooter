#pragma once

#include "../common/vector2.h"
#include "../texture/texture.h"
#include "../window.h"

namespace spaceshooter {

const int ANCHOR_PIVOT_TOP = 0b0100;
const int ANCHOR_PIVOT_BOTTOM = 0b1000;
const int ANCHOR_PIVOT_LEFT = 0b0001;
const int ANCHOR_PIVOT_RIGHT = 0b0010;

const int ANCHOR_PIVOT_V_CENTER = 0b1100;
const int ANCHOR_PIVOT_H_CENTER = 0b0011;

const int MASK_V = 0b0011;
const int MASK_H = 0b1100;

enum Anchor {
    kTopLeft = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_LEFT,
    kTopRight = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_RIGHT,
    kTopCenter = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_LEFT | ANCHOR_PIVOT_RIGHT,
    kCenterLeft = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_LEFT,
    kCenterRight = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_RIGHT,
    kCenterCenter = ANCHOR_PIVOT_TOP | ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_LEFT | ANCHOR_PIVOT_RIGHT,
    kBottomLeft = ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_LEFT,
    kBottomRight = ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_RIGHT,
    kBottomCenter = ANCHOR_PIVOT_BOTTOM | ANCHOR_PIVOT_LEFT | ANCHOR_PIVOT_RIGHT
};

using Pivot = Anchor;

enum ViewType {
    kFill,
    kWrapContent,
};

struct ViewInfo {
    Vector2 pos;
    Vector2 size;
    ViewType h_view_type;
    ViewType v_view_type;
    Pivot pivot;
    Anchor anchor;
};

class View {
 public:
    View();

    virtual ~View();

    void set_window(Window* window);

    void SetPos(Vector2 pos);
    void SetSize(Vector2 size);
    void SetHViewType(ViewType view_type);
    void SetVViewType(ViewType view_type);
    void SetAnchor(Anchor anchor);
    void SetPivot(Pivot pivot);
    void Render(SDL_Renderer* renderer);

 protected:
    ViewInfo view_info_;
    Texture* texture_;
    Window* window_;
};

} // namespace spaceshooter
