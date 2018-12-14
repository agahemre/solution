//
// Created by eagah on 12/13/2018.
//

#ifndef SOLUTION_BALL_HPP
#define SOLUTION_BALL_HPP

#include "Point2D.hpp"

struct Ball {
    emc::Point2D position;

    // Ball() : position(std::move(emc::Point2D())) {};

    void updatePosition(float, float);
    void updatePosition(const emc::Point2D&);
    emc::Point2D negatePosition();
    void negatePosition(emc::Point2D&);
    void resetPosition();
    emc::Point2D mirrorPosition();

};


#endif //SOLUTION_BALL_HPP
