/*
 *  @name: Definitions.h
 *  @author: EA
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdio.h>
#include <stddef.h>

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

// this enumeration defines a partition scheme
typedef enum {HOARE, LOMUTO} PARTITION;

const int SUCCESS = 8;
const int NOT_FOUND = -1;

// This constant defines UTF-8 character set
static const char charset[] = {'!','"','#','$','%',
                        '&','\'','(',')','*',
                        '+',',','-','.','/',
                        '0','1','2','3','4',
                        '5','6','7','8','9',
                        ':',';','<','=','>',
                        '?','@','A','B','C','D',
                        'E','F','G','H','I',
                        'J','K','L','M','N',
                        'O','P','Q','R','S','T',
                        'U','V','W','X','Y','Z',
                        '[','\\',']','^','_','`',
                        'a','b','c','d','e','f',
                        'g','h','i','j','k',
                        'l','m','n','o','p',
                        'q','r','s','t','u',
                        'v','w','x','y','z',
                        '{','|','}','~',' '};

#endif /* DEFINITIONS_H_ */
