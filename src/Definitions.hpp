//
// Created by eagah on 12/13/2018.
//

#ifndef SOLUTION_DEFINITIONS_HPP
#define SOLUTION_DEFINITIONS_HPP


// This constant defines number of max. possible neighbour `cell`s
const int DIRECTION_COUNT = 8;

// This constant defines X-Y coordinates
const int COORDINATE = 2;

// This array defines possible (at most 8) directions for a particular `cell`
const float direction[DIRECTION_COUNT][COORDINATE] = {{-1.0f,-1.0f},{0.0f,-1.0f},{1.0f,-1.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f},{-1.0f,1.0f},{-1.0f,0.0f}};

#endif //SOLUTION_DEFINITIONS_HPP
