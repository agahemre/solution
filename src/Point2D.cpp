//
// Created by eagah on 12/11/2018.
//

#include "Point2D.hpp"

namespace emc
{
    void Point2D::reset() {
        x = 0.0f;
        y = 0.0f;
    };
    void Point2D::negate() {
        x *= utility::NEGATE_FACTOR;
        y *= utility::NEGATE_FACTOR;
    }
    void Point2D::update(float x, float y) {
        x = x;
        y = y;
    }
}




