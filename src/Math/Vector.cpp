#include "Vector.hpp"

namespace MarsGE {
    namespace Math {
        Vector::PolarCoords::PolarCoords(double rad, double ang) {
            this->radius = rad; this->angle = ang;
        }
        Vector::SphericalCoords::SphericalCoords(double rad, double inc, double az) {
            this->radius = rad; this->inclination = inc; this->azimuth = az;
        }
        Vector::Vector() throw() {
            // pass
        }
        Vector::Vector(const Vector& p) throw() {
            this->x = p.x;
            this->y = p.y;
            this->z = p.z;
        }
        Vector::Vector(int x, int y, int z) throw() {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        double Vector::getMagnitude() const throw() {
            return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
        }
        Vector::SphericalCoords Vector::getSphericalCoords() const throw() {
            double mag = getMagnitude();
            return SphericalCoords(mag, toAngle(acos(z / mag)), toAngle(atan2(y,x)));
        }
        Vector::PolarCoords Vector::getPolarCoords() const throw() {
            return PolarCoords(getMagnitude(), atan2(y,x) * 180 / Math::PI);
        }
        Vector Vector::operator*(double scalar) const throw() {
            return Vector(scalar * this->x, scalar * this->y, scalar * this->z);
        }
        Vector Vector::operator+(const Vector& vect) const throw() {
            return Vector(this->x + vect.x, this->y + vect.y, this->z + vect.z);
        }
        Vector Vector::operator-(const Vector& vect) const throw() {
            return Vector(this->x - vect.x, this->y - vect.y, this->z - vect.z);
        }
        Vector& Vector::operator=(const Vector& vect) throw() {
            Point::operator=(vect);
            return *this;
        }
        double Vector::dotProduct(const Vector& vector) const throw() {
            return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
        }
        Vector Vector::crossProduct(const Vector& vector) const throw() {
            return Vector((this->y * vector.z) - (this->z * vector.y), 
                          (this->z * vector.x) - (this->x * vector.z),
                          (this->x * vector.y) - (this->y * vector.x));
        }
    }
}