/**
 * @author: summer
 */

#pragma once

#ifndef SOLUTION_POINT_HXX
#define SOLUTION_POINT_HXX

#include "Definitions.hpp"

namespace emc {

    struct Point2D {
        float x;
        float y;

        Point2D() : x(0.0f), y(0.0f) {};
        Point2D(float x, float y) : x(x), y(y) {};
        Point2D(const Point2D& other) : x(other.x), y(other.y) {};

        Point2D& operator=(const Point2D& right) {
            if (&right != this) {
                this->x = right.x;
                this->y = right.y;
            }
            return *this;
        }

        void reset();
        void negate();
        void update(float, float);
    };

    inline bool operator==(const Point2D& left, const Point2D& right) {
        return (left.x == right.x) && (left.y == right.y);
    }

    inline Point2D operator*(const Point2D& left, float right) {
        return Point2D((left.x * right), (left.y * right));
    }

    inline Point2D operator*(float left, const Point2D& right) {
        return Point2D((right.x * left), (right.y * left));
    }

    inline Point2D& operator*=(Point2D& left, const Point2D& right) {
        left.x *= right.x;
        left.y *= right.y;
        return left;
    }

    inline Point2D& operator*=(Point2D& left, float right) {
        left.x *= right;
        left.y *= right;
        return left;
    }

    inline Point2D operator+(const Point2D& left, const Point2D& right) {
        return Point2D((left.x + right.x), (left.y + right.y));
    }

    inline Point2D& operator+=(Point2D& left, const Point2D& right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }

    inline Point2D operator-(const Point2D& right) {
        return Point2D(-right.x, -right.y);
    }

    inline Point2D& operator-=(Point2D& left, const Point2D& right) {
        left.x -= right.x;
        left.y -= right.y;
        return left;
    }

    inline Point2D operator/(const Point2D& left, float right) {
        return Point2D((left.x / right), (left.y / right));
    }

    inline Point2D operator/=(Point2D& left, const Point2D& right) {
        left.x /= right.x;
        left.y /= right.y;
        return left;
    }

    inline Point2D operator-(const Point2D& left, const Point2D& right) {
        return Point2D((left.x - right.x), (left.y - right.y));
    }

    inline bool operator!=(const Point2D& left, const Point2D& right) {
        return (left.x != right.x) || (left.y != right.y);
    }

    inline Point2D operator~(const Point2D& right) {
        return Point2D(right.y, right.x);
    }
}



#endif //SOLUTION_POINT_HXX
