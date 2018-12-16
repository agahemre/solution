/**
 * @author: summer
 */

#pragma once

#ifndef SOLUTION_DEFINITIONS_HPP
#define SOLUTION_DEFINITIONS_HPP

namespace utility
{

// This constant defines the negate factor
const float NEGATE_FACTOR = -1.0f;

// This constant defines number of max. possible neighbour `cell`s
const int DIRECTION_COUNT = 8;

// This constant defines X-Y coordinates
const int COORDINATE = 2;

// This array defines possible (at most 8) directions for a particular `cell`
const float direction[DIRECTION_COUNT][COORDINATE] = {{-1.0f,-1.0f},{0.0f,-1.0f},{1.0f,-1.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f},{-1.0f,1.0f},{-1.0f,0.0f}};

// TODO: Design board member
// This constant defines the position of the lower bound for y-axis
const float LOWER_BOUND_Y = -15.0f;

// This constant defines the position of the upper bound for y-axis
const float UPPER_BOUND_Y = 15.0f;

// This constant defines the position of the right bound for x-axis
const float RIGHT_BOUND_X = 25.0f;

// This constant defines the position of the left bound for x-axis
const float LEFT_BOUND_X = 25.0f;

}

#endif //SOLUTION_DEFINITIONS_HPP
