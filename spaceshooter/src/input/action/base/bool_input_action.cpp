#include "../../../../include/input/action/base/bool_input_action.h"

namespace spaceshooter {

BoolInputAction::BoolInputAction(bool value) : value_(value) {}

bool BoolInputAction::get_value() { return value_; }

} // namespace spaceshooter
