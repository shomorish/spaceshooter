#include "image_view.h"

namespace spaceshooter {

ImageView::ImageView() {}

ImageView::~ImageView() {}

void ImageView::SetImage(Texture* texture) { texture_ = texture; }

} // namespace spaceshooter