#pragma once

namespace spaceshooter {

enum State { kWait, kRun, kPause, kGameClear, kGameOver };

class Stage1State {
 public:
    Stage1State();

    ~Stage1State();

    State get_state();
    void set_state(State state);

    void Init(State state, int num_of_enemies);
    void DecrementEnemy();

 private:
    State state_;
    int num_of_enemies_;
};

} // namespace spaceshooter
