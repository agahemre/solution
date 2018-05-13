/*
 *  @name: Definitions.h
 *  @author: EA
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdio.h>

// this structure defines a tree (non-linear) node property
struct Node2
{
	int key;
	Node2 *left;
	Node2 *right;
	Node2(int k) : key(k), left(NULL), right(NULL)  {}
};

// this structure defines a AVL tree node property
struct Node3
{
	int key;
	int height;
	Node3 *left;
	Node3 *right;
	Node3(int k) : key(k), height(0), left(NULL), right(NULL) {}
};

// this structure defines a linear node property
struct Node
{
	int key;
	Node *next;
	Node(int k) : key(k), next(NULL) {}
};

// this enumeration defines a rotation direction
typedef enum {CCW=1, CW=0} DIRECTION;

#endif /* DEFINITIONS_H_ */
