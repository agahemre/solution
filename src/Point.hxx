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

    const Point& operator+=(const Point& o) {
        this->x += o.x;
        this->y += o.y;
        return *this;
    }

    const Point& operator-=(const Point& o) {
        this->x -= o.x;
        this->y -= o.y;
        return *this;
    }

    const Point& operator*=(const Point& o) {
        this->x *= o.x;
        this->y *= o.y;
        return *this;
    }

    const Point& operator*=(int m) {
        this->x *= m;
        this->y *= m;
        return *this;
    }

    const Point& operator+(const Point& o) {
        float dX = this->x + o.x;
        float dY = this->y + o.y;
        return Point(dX, dY);
    }

    const Point& operator*(const Point& o) {
        float dX = this->x * o.x;
        float dY = this->y * o.y;
        return Point(dX, dY);
    }

    const Point& inverse(float x, float y) {
        this->x = y;
        this->y = x;
        return *this;
    }

};

namespace point
{
    bool operator==(const Point& p2, const Point& p1) {
        return (p2.x == p1.x) && (p2.y == p1.y);
    }

    bool operator!=(const Point& p2, const Point& p1) {
        return (p2.x != p1.x) || (p2.y != p2.x);
    }


}



#endif //SOLUTION_POINT_HXX
