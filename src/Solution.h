/*
 *  @name: Solution.h
 *  @author: EA
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <stdio.h>
#include <vector>
#include "Definitions.h"

// This name space contains various algorithm & data structure problems' definition*
namespace solution
{
	void inorder_tree_walk (Node2 *);
	void levelorder_tree_walk (Node2 *);
	Node2* search (Node2 *, int);
	Node2* iterative_tree_search (Node2 *, int);
	Node2* iterative_randomized_tree_search (Node2 *, int);
	Node2* construct_maximum_binary_tree(const std::vector<int>&); // LEETCODE
	bool check_BST (Node2 *); // LEETCODE
	bool check_balanced (Node2 *); // LEETCODE
	Node2* inverse (Node2 *);	// LEETCODE
	std::vector<double> av_of_levels (Node2 *); // LEETCODE
	std::vector<int> largest_value_of_levels (Node2 *); // LEETCODE
	Node* get_middle_node(Node *);
	bool detect_cycle (Node *); // LEETCODE
	Node* detect_cycle_node (Node *); // LEETCODE
	int is_palindrome (Node *);	// LEETCODE
	int is_palindrome (std::string);
	int has_valid_parentheses (std::string); // LEETCODE

	/**
	 * @description : following functions are helper functions for has_valid_parentheses function
	 */
	inline bool is_valid (const char p, const char q)
	{
		return ( (p == '{' && q == '}') || (p == '[' && q == ']') || (p == '(' && q == ')') );
	}

	inline bool is_opened (const char p)
	{
		return (p == '{' || p == '[' || p == '(');
	}

	inline bool is_closed (const char q)
	{
		return (q == '}' || q == ']' || q == ')');
	}

	// utility functions
	Node2* insert_key (Node2 *, int);
	void delete_node (Node2 *, int);
	void flatten (Node2 *, DIRECTION); // LEETCODE
	void flatten_r (Node2 *);
	void flatten_l (Node2 *);
	Node* remove_nth_from_end (Node *, int); // LEETCODE
	Node2* min(Node2 *);
	Node2* max(Node2 *);
	Node2* successor (Node2 *, Node2 *);
	Node2* predecessor (Node2 *, Node2 *);
	Node2* lca (Node2 *, Node2 *, Node2 *); // LEETCODE
	bool exist(Node2 *, int);
	int height (Node2 *);
	int height_iterative (Node2 *);
	int min_depth (Node2 *); // LEETCODE
	int length (Node *); // LEETCODE
	int length (Node *, int);
	Node* reverse (Node *);
	Node* reverse (Node *, int, int); // LEETCODE
	std::vector<int> reverse (std::vector<int>&, int, int);
	std::vector<int> rotate_rl (std::vector<int>&, int, DIRECTION);
	Node* rotate_r (Node *, int); // LEETCODE
	Node* rotate_r_one (Node *); // LEETCODE
	void print_r (Node *);
	void push_back (Node **, int);
	void print_r (char *);
	void push_r (Node *, std::vector<int>&);

	int search (const std::vector<int>&, int, int, int);
	int max (const std::vector<int>&, int, int);
	int max (const std::vector<int>&, int);
	int k_small (int, std::vector<int>&, int, int);
	int k_small (Node2 *, int); // LEETCODE
	int k_small (int, Node2 *); // LEETCODE
	int k_largest (std::vector<int>&, int); // LEETCODE
	int h_partition (std::vector<int>&, int, int);
	int l_partition (std::vector<int>&, int, int);
	void construct_vector (Node2 *, std::vector<int>&);
	int find_maximum_occurrence (std::vector<const char *>&);
	void print_pair_sum (std::vector<int>&, int);

	void swap (int *, int *);
	int compare (std::string, std::string);

	const int SUCCESS = 8;
	const int NOT_FOUND = -1;
}

#endif /* SOLUTION_H_ */
