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

void Ball::updatePosition(const emc::Point2D& point2D) {
    this->position = point2D;
}

void Ball::negatePosition(emc::Point2D& point2D) {
    point2D.negate();
}

emc::Point2D Ball::negatePosition() {
    return -this->position;
}

void Ball::mirrorVelocity() {

    if (isYPositionOnBorder() && isYPositionOnBorder()) {
        negatePosition(position);
    } else if (isXPositionOnBorder()) {
        position.y *= utility::NEGATE_FACTOR;
    }else if (isYPositionOnBorder()) {
        position.x *= utility::NEGATE_FACTOR;
    }
}

bool Ball::isXPositionOnBorder() {
    return (this->position.x <= utility::LEFT_BOUND_X) || (this->position.x >= utility::RIGHT_BOUND_X);
}

bool Ball::isYPositionOnBorder() {
    return (this->position.y <= utility::LOWER_BOUND_Y) || (this->position.y >= utility::UPPER_BOUND_Y);
}




