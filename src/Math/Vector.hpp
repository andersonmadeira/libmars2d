#ifndef __MARSGAMEENGINE_VECTOR_HPP__
#define __MARSGAMEENGINE_VECTOR_HPP__

#include "Point.hpp"

namespace MarsGE {
    namespace Math {
        /// Vector is a specialied Point class
        class Vector : public Point {
        public:
            /// more at: http://www.mathsisfun.com/polar-cartesian-coordinates.html
            struct PolarCoords;
            /// more at: http://en.wikipedia.org/wiki/Spherical_coordinate_system
            struct SphericalCoords;
            Vector() throw();
            Vector(const Vector& v) throw();
            Vector(int x, int y, int z = 0) throw();
            double getMagnitude() const throw();
            SphericalCoords getSphericalCoords() const throw();
            PolarCoords getPolarCoords() const throw();
            Vector operator+(const Vector& vect) const throw();
            Vector operator-(const Vector& vect) const throw();
            Vector operator*(double scalar) const throw();
            Vector& operator=(const Vector& vect) throw();
            double dotProduct(const Vector& vector) const throw();
            Vector crossProduct(const Vector& vector) const throw();
            /// more at: http://www.mathsisfun.com/polar-cartesian-coordinates.html
            struct PolarCoords {
                double radius, angle;
                PolarCoords(double rad, double ang);
            };
            /// more at: http://en.wikipedia.org/wiki/Spherical_coordinate_system
            struct SphericalCoords {
                double radius, inclination, azimuth;
                SphericalCoords(double rad, double inc, double az);
            };
        };
    }
}

#endif