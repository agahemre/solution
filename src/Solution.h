/*
 *  @name: Solution.h
 *  @author: EA
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "Definitions.h"
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

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
	std::vector<int> right_side_view (Node2 *); // LEETCODE
	bool has_path_sum (Node2 *, int); // LEETCODE
	int path_sum (Node2 *, int); // LEETCODE
	void path_sum (Node2 *, int, int&);
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
	Node* rotate_r (Node *, int); // LEETCODE
	Node* rotate_r_one (Node *); // LEETCODE
	void print_r (Node *);
	void push_back (Node **, int);
	void print_r (char *);
	void push_r (Node *, std::vector<int>&);
	int max (const std::vector<int>&, int, int);
	int max (const std::vector<int>&, int);
	int k_small (int, std::vector<int>&, int, int);
	int k_small (Node2 *, int); // LEETCODE
	int k_small (int, Node2 *); // LEETCODE
	int k_largest (std::vector<int>&, int); // LEETCODE
	void construct_vector (Node2 *, std::vector<int>&);

	// @usage : swap (X, Y)
	template <typename type_t> void swap (type_t& __first, type_t& __second)
	{
		// local data
		type_t temp = __first; // O(1) In Place
		__first = __second;
		__second = temp;
	}

	// This function reverses the given vector, i as start index and j as last index
	template <typename type_t> std::vector<type_t> reverse (std::vector<type_t>& __array, int i, int j)
	{
		// WHILE I-TH index smaller than J-TH index, then,
		// SWAP the elements and move the indices towards each other
		while (i < j)
		{
			swap(__array[i], __array[j]);

			// Increment start index and decrement last index by 1 for each iteration
			i++; j--;
		}

		return __array; // result of this function changes the original array
	}

	// This function implements the reversal algorithm for array rotation
	template <typename type_t> std::vector<type_t> rotate (std::vector<type_t>& __array, int k, DIRECTION d)
	{
		// local data
		int n = __array.size();

		if (n == 0) return __array; // defensive check

		// LEETCODE test update
		k = k % n;

		// this means direction CCW, left rotate by k
		if (CCW == d)
		{
			// split the array properly
			reverse (__array, 0, k-1);
			reverse (__array, k, n-1);
		}
		// this means direction CW, right rotate by k
		else
		{
			// split the array properly
			reverse (__array, 0, n-k-1);
			reverse (__array, n-k, n-1);
		}

		// reverse of reverse
		return reverse (__array, 0, n-1);
	}

	// This function searches target in the given sorted array
	template <typename type_t> int search (const std::vector<int>& __array, int __first, int __last, type_t __target)
	{
		if (__first <= __last)
		{
			int mid = __first + (__last - __first) / 2; // avoid overflow a negative value

			// base case ii) 'found'
			if (__target == __array[mid])
				return mid;
			else if (__target > __array[mid]) // continue to search in array::RIGHT
				return search (__array, (mid+1), __last, __target);
			else // continue to search in array::LEFT
				return search (__array, __first, (mid-1), __target);
		}
		// base case i) 'not found' when first index exceeds last index

		return NOT_FOUND; // search miss
	}

	// This function implements the Lomuto's partition
	template <typename type_t> int l_partition (std::vector<type_t>& __array, int p, int r)
	{
		type_t pivot = __array[r]; // select pivot as last element
		int i = p - 1;

		for (int j = p; j <= r - 1; j++)
		{
			if (__array[j] <= pivot)
			{
				i = i+1;
				swap (__array[i], __array[j]);
			}
		}

		swap (__array[i+1], __array[r]);
		return (i+1);
	}

	// This function implements the Hoare's partition
	template <typename type_t> int h_partition (std::vector<type_t>& __array, int p, int q)
	{
		// TODO
	}

	// This function finds the number of maximum occurrences amongst elements of the given list
	template <typename type_t> int find_max_occur (std::vector<type_t>& __array)
	{
		// local data
		int max_occur = 0;
		std::unordered_map<type_t, int> temp;

		for (auto const& e : __array)
		{
			if (temp.find(e) == temp.end()) // not contain
				temp.insert(std::pair<type_t, int> (e, 1) );
			else // already contain
				temp.find(e)->second = 1 + temp.find(e)->second; // simply increment the occurrence
		}

		// @note : maximum occurrence remains zero if empty list (array) passed before
		max_occur = std::max_element(temp.begin(), temp.end(),
				// lambda expression begins
				[](const std::pair<type_t, int>& __p, const std::pair<type_t, int>& __q) {
					return __p.second < __q.second;
				})->second;

		return max_occur;
	}

	void print_pair_sum (std::vector<int>&, int);
	void custom_sort (std::vector<int>&);
	int compare (std::string, std::string);
	std::string merge_str (std::string, std::string);
	std::string merge_str (std::string, std::string, unsigned int);
}

#endif /* SOLUTION_H_ */
