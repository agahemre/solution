//
// Created by eagah on 12/11/2018.
//

#ifndef SOLUTION_POINT_HXX
#define SOLUTION_POINT_HXX

#include <utility>

namespace emc {

    const float NEGATE_FACTOR = -1.0f;

    struct Point2D {
        float x;
        float y;

        Point2D() : x(0.0f), y(0.0f) {};
        Point2D(float x, float y) : x(x), y(y) {};
        Point2D(const Point2D& other) = delete;
        Point2D(Point2D&& other) : x(std::move(other.x)), y(std::move(other.y)) {};

        Point2D& operator=(const Point2D& other) = delete;
        Point2D& operator=(Point2D&& other) {
            if (&other != this) {
                this->x = std::move(other.x);
                this->y = std::move(other.y);
            }
            return *this;
        }

        void reset() {
            this->x = 0.0f;
            this->y = 0.0f;
        };
        void negate() {
            this->x *= NEGATE_FACTOR;
            this->y *= NEGATE_FACTOR;
        }
    };

    bool operator==(const Point2D& left, const Point2D& right) {
        return (left.x == right.x) && (left.y == right.y);
    }

    bool operator!=(const Point2D& left, const Point2D& right) {
        return (left.x != right.x) || (left.y != right.y);
    }

    Point2D operator*(const Point2D& left, float right) {
        float dX = left.x * right;
        float dY = left.y * right;
        return Point2D(dX, dY);
    }

    Point2D operator*(float left, const Point2D& right) {
        float dX = left * right.x;
        float dY = left * right.y;
        return Point2D(dX, dY);
    }

    Point2D& operator*=(Point2D& left, const Point2D& right) {
        left.x *= right.x;
        left.y *= right.y;
        return left;
    }

    Point2D& operator*=(Point2D& left, float right) {
        left.x *= right;
        left.y *= right;
        return left;
    }

    Point2D operator+(const Point2D& left, const Point2D& right) {
        float dX = left.x + right.y;
        float dY = left.y + right.y;
        return Point2D(dX, dY);
    }

    Point2D& operator+=(Point2D& left, const Point2D& right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }

    Point2D operator-(const Point2D&& right) {
        float nX = NEGATE_FACTOR * right.x;
        float nY = NEGATE_FACTOR * right.y;
        return Point2D(nX, nY);
    }

    Point2D operator-(const Point2D& left, const Point2D& right) {
        float dX = left.x - right.x;
        float dY = left.y - right.y;
        return Point2D(dX, dY);
    }

    Point2D& operator-=(Point2D& left, const Point2D& right) {
        left.x -= right.x;
        left.y -= right.y;
        return left;
    }

    Point2D operator~(const Point2D&& right) {
        return Point2D(right.y, right.x);
    }
}



#endif //SOLUTION_POINT_HXX
