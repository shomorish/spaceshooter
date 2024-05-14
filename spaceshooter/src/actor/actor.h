#pragma once

namespace spaceshooter {

class Actor {
 public:
    Actor();

    virtual ~Actor();

    bool get_is_destroyed();

    void Destroy();

 protected:
    bool is_destroyed_;
};

} // namespace spaceshooter
