#include "stage1_state.h"

namespace spaceshooter {

Stage1State::Stage1State() : state_(State::kWait), num_of_enemies_(0) {}

Stage1State::~Stage1State() {}

State Stage1State::get_state() { return state_; }

void Stage1State::set_state(State state) { state_ = state; }

void Stage1State::Init(State state, int num_of_enemies) {
    state = state;
    num_of_enemies_ = num_of_enemies;
}

void Stage1State::DecrementEnemy() {
    num_of_enemies_ -= 1;
    if (num_of_enemies_ == 0) {
        state_ = State::kGameClear;
    }
}

} // namespace spaceshooter