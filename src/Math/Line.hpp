#ifndef __MARSGAMEENGINE_LINE_HPP__
#define __MARSGAMEENGINE_LINE_HPP__

#include "Vector.hpp"

namespace MarsGE {
    namespace Math {
        struct Line {
            Line(const Point& start, const Point& end);
            Vector toVector() const throw();
            // public attrs
            Point s, e;
        };
    }
}

#endif