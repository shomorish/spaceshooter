#pragma once

#include <stdexcept>

namespace spaceshooter {

template <class A, class B> B* SafeCast(A* a) {
    try {
        return dynamic_cast<B*>(a);
    } catch (std::exception e) {
        return NULL;
    }
}

} // namespace spaceshooter
