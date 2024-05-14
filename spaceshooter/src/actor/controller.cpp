#include "controller.h"

namespace spaceshooter {

Controller::Controller() : character_(NULL) {}

Controller::~Controller() {}

Character* Controller::get_character() { return character_; }

} // namespace spaceshooter