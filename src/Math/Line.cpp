#include "Line.hpp"

namespace MarsGE {
    namespace Math {
        Line::Line(const Point& start, const Point& end) : s(start), e(end) {
            // pass
        }
        
        Vector Line::toVector() const throw() {
            return Vector(e.x - s.x, e.y - s.y, e.z - s.z);
        }
    }
}