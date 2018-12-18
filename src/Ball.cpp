/*
 * @author: summer
 */

#include "Ball.hpp"

void Ball::resetPosition() {
    position.reset();
}

void Ball::updatePosition(float x, float y) {
    position.update(x, y);
}

void Ball::updatePosition(const emc::Point2D& point2D) {
    position = point2D;
}

void Ball::negatePosition(emc::Point2D& point2D) {
    point2D.negate();
}

emc::Point2D Ball::negatePosition() {
    return -position;
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
    return (position.x <= utility::LEFT_BOUND_X) || (position.x >= utility::RIGHT_BOUND_X);
}

bool Ball::isYPositionOnBorder() {
    return (position.y <= utility::LOWER_BOUND_Y) || (position.y >= utility::UPPER_BOUND_Y);
}




