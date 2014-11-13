#ifndef __MARSGAMEENGINE_POINT_HPP__
#define __MARSGAMEENGINE_POINT_HPP__

#include <vector>
#include "Utility.hpp"

namespace MarsGE {
    namespace Math {
        /// Point Class
        class Point {
        public:
            Point() throw();
            Point(const Point& p) throw();
            Point(double x, double y, double z = 0) throw();
            Point& operator=(const Point& p) throw();
            double distance(const Point& p) const throw();
        public:
            double x, y, z;
        };
        
    }
}

#endif