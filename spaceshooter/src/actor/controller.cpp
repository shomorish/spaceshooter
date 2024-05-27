#include "controller.h"

namespace spaceshooter {

Controller::Controller(Level* level) : level_(level), character_(NULL) {}

Controller::~Controller() { level_ = NULL; }

Character* Controller::get_character() { return character_; }

void Controller::Tick(const InputActionContainer* action_container, const float& delta_time) {}

Character** Controller::GetCharacterRef() { return &character_; }

void Controller::DestroyCharacter() {}

} // namespace spaceshooter