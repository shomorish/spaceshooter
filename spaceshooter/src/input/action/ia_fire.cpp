#include "../../../include/input/action/ia_fire.h"

namespace spaceshooter {

IA_Fire::IA_Fire(bool value) : BoolInputAction(value) {}

IA_Fire::~IA_Fire() { value_ = false; }

} // namespace spaceshooter