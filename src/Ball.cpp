//
// Created by eagah on 12/14/2018.
//

#include "Ball.hpp"

void Ball::resetPosition() {
    this->position.reset();
}

void Ball::updatePosition(float x, float y) {
    this->position.update(x, y);
}

void Ball::updatePosition(const emc::Point2D& position) {
    this->position = position;
}

void Ball::negatePosition(emc::Point2D& point2D) {
    point2D.negate();
}

emc::Point2D Ball::negatePosition() {
    return -this->position;
}

// This function translates given Point(x,y) into Point(y,x) [--mirror]
emc::Point2D Ball::mirrorPosition() {
    return ~this->position;
}


