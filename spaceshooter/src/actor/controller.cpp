#include "controller.h"

namespace spaceshooter {

Controller::Controller() : character_(NULL) {}

Controller::~Controller() { character_ = NULL; }

void Controller::AttachCharacter(Character* character) { character_ = character; }

void Controller::DetachCharacter() { character_ = NULL; }

} // namespace spaceshooter