#include "controller.h"

namespace spaceshooter {

Controller::Controller() : character_(NULL) {}

Controller::~Controller() {}

Character* Controller::get_character() { return character_; }

Character** Controller::GetCharacterRef() { return &character_; }

void Controller::DestroyCharacter() {}

} // namespace spaceshooter