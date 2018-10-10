/**
 * @name: gof.h
 * @author: EA
 */

#ifndef SOLUTION_GOF_H
#define SOLUTION_GOF_H

// This constant defines number of max. possible neighbour `cell`s
const int MAX_NEIGHBOUR = 8;

// This constant defines X-Y coordinates
const int _X_Y = 2;

// This array defines possible (at most 8) directions for a particular `cell`
const int direction[MAX_NEIGHBOUR][_X_Y] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

#endif //SOLUTION_GOF_H
