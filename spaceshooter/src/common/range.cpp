#include "range.h"

namespace spaceshooter {

bool Range::withinRange(float current) { return min <= current && current <= max; }

} // namespace spaceshooter