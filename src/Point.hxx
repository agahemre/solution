//
// Created by eagah on 12/11/2018.
//

#ifndef SOLUTION_POINT_HXX
#define SOLUTION_POINT_HXX

struct Point
{
    float x;
    float y;
    Point() : x(0.0f), y(0.0f) {};
    Point(float x, float y) : x(x), y(y) {};
};

const unsigned int NEGATE_FACTOR = 1;

namespace point2D {
    bool operator==(const Point& left, const Point& right) {
        return (left.x == right.x) && (left.y == right.y);
    }

    bool operator!=(const Point& left, const Point& right) {
        return (left.x != right.x) || (left.y != right.y);
    }

    const Point& operator+=(Point& left, const Point& right) {
        left.x += right.x;
        left.y += right.y;
        return left;
    }

    const Point& operator-=(Point& left, const Point& right) {
        left.x -= right.x;
        left.y -= right.y;
        return left;
    }

    const Point& operator*=(Point& left, const Point& right) {
        left.x *= right.x;
        left.y *= right.y;
        return left;
    }

    const Point& operator*=(Point& left, const float scalar) {
        left.x *= scalar;
        left.y *= scalar;
        return left;
    }

    Point operator*(const float scalar, const Point& point) {
        float dX = scalar * point.x;
        float dY = scalar * point.y;
        return Point(dX, dY);
    }

    Point operator+(const Point& left, const Point& right) {
        float dX = left.x + right.y;
        float dY = left.y + right.y;
        return Point(dX, dY);
    }

    Point operator-(const Point& left, const Point& right) {
        float dX = left.x - right.x;
        float dY = left.y - right.y;
        return Point(dX, dY);
    }

    Point operator-(const Point& right) {
        float nX = NEGATE_FACTOR * right.x;
        float nY = NEGATE_FACTOR * right.y;
        return Point(nX, nY);
    }

    Point inverse(const float x, const float y) {
        return Point(y, x);
    }
}



#endif //SOLUTION_POINT_HXX
