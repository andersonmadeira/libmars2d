#include "Point.hpp"

namespace MarsGE {
    namespace Math {
        Point::Point() throw() {
            this->x = this->y = this->z = 0;
        }
        Point::Point(const Point& p) throw() {
            this->x = p.x;
            this->y = p.y;
            this->z = p.z;
        }
        Point::Point(double x, double y, double z) throw() {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        Point& Point::operator=(const Point& p) throw() {
            this->x = p.x;
            this->y = p.y;
            this->z = p.z;
            return *this;
        }
        double Point::distance(const Point& p) const throw() {
            return sqrt( ((this->x - p.x) * (this->x - p.x)) + ((this->y - p.y) * (this->y - p.y)) );
        }
    }
}