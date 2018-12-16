/**
 * @summer
 */

#ifndef SOLUTION_CONVERSION_HPP
#define SOLUTION_CONVERSION_HPP

#define _USE_MATH_DEFINES
#include <cmath>


namespace conversion {

    double radian2angle(double radian) {
        radian = fmod(radian, M_PI);
        return radian < 0.0 ? -radian * (180.0 / M_PI) : radian * (180.0 / M_PI);
    }

    float angle2radian(float angle) {
        angle = fmodf(angle, 360.0f);
        return angle < 0.0f ? (angle += 360.0f) * (M_PI / 180.0f) : angle * (M_PI / 180.0f);
    }

}

#endif //SOLUTION_CONVERSION_HPP
