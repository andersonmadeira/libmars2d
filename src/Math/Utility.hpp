#ifndef __MARSGAMEENGINE_UTILITY_HPP__
#define __MARSGAMEENGINE_UTILITY_HPP__

#include <cmath>
#include <utility>

namespace MarsGE {
    namespace Math {
        const double PI = 3.14159265;
        inline double toAngle(double rad) {
            return rad * (180.0 / PI);
        }
        inline double toRadians(double angle) {
            return angle * (PI / 180.0);
        }
    }
}

#endif