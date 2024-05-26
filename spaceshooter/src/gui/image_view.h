#pragma once

#include "view.h"

namespace spaceshooter {

class ImageView : public View {
 public:
    ImageView();

    ~ImageView();

    void SetImage(Texture* texture);
};

} // namespace spaceshooter
