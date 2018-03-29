/*
 *  @name: Solution.cpp
 *  @author: EA
 */

#include <stack>
#include <map>
#include <unordered_map>
#include "Solution.h"
#include <math.h>
#include <climits>

#define SUCCESS 8
#define NOT_FOUND -1

/**
 * description : INORDER TREE WALK can be explained as first visit the left node,
 * then,
 * go through the its root node
 * then, goto right node
 */
// This function INORDER traversal in recursive way.
void Solution::inorder_tree_walk(Node2 *root)
{
	inorder_tree_walk (root->left);
	printf ("%d\t", root->key);
	inorder_tree_walk (root->right);
}

// This function calculates the height of binary tree by using recursion
int Solution::height(Node2 *root)
{
	// base case i)
	if (root == NULL)
		return 0;

	int left_height = height (root->left);
	int right_height = height (root->right);

	return 1 + std::max( right_height, left_height );
}

// This function calculates height of the binary tree in iterative way
int Solution::height_iterative(Node2 *root)
{
	// TODO
}

// This function constructs the binary tree at maximum possible height from vector
Node2* Solution::construct_maximum_binary_tree(const std::vector<int>& A)
{
	// TODO
}

// This function checks whether given binary tree is an actually binary search tree or not
bool Solution::check_BST(Node2 *root)
{
	// base case i) called just after leaf node
	if (root == NULL)	return true;

	// local data
	Node2 *right = min (root->right); // find the minimum value of right subtree and use it to compare with root
	Node2 *left = max (root->left); // find the maximum value of left subtree and use it to compare with root

	// breaks the binary search tree rule
	if (right != NULL && right->key <= root->key)	return false;

	// breaks the binary search tree rule
	if (left != NULL && left->key > root->key)	return false;

	return (check_BST (root->right) && check_BST (root->left)); // check both subtrees
}

/*
 * This function returns with the node containing the key, otherwise search miss (returning NULL)
 * Note: this function searches the key in given BST
 */
Node2* Solution::search (Node2 *root, int key)
{
	// base case i)
	if ( (root == NULL) || (key == root->key)) return root;

	if (key > root->key)	// seek RIGHT subtree
		return search (root->right, key);
	else	// seek LEFT subtree
		return search (root->right, key);
}

/*
 * This function returns with the node containing the key, otherwise search miss (returning NULL)
 * Note: this function searches the key in given BT instead of BST
 */
Node2* Solution::search (int key, Node2 *root)
{
	// base case i)
	if ( (root == NULL) || (key == root->key)) return root;

	// TODO
}

// This function searches the key provided as @param.
// Assumption is root points the BST,
Node2* Solution::iterative_tree_search	(Node2 *root, int key)
{
	// local data
	Node2 *curr = root;

	while ( (curr != NULL) && (key != curr->key) )
	{
		// This is the rule set from definition of Binary Search Tree (BST)
		if (key < curr->key) // seek from left subtree
			curr = curr->left;
		else // seek from right subtree
			curr = curr->right;
	}
	// What if we construct binary tree instead of BST ?

	return curr; // either key found or current left as NULL
}
// This function searches the key provided as @param.
// Assumption is root points the Binary Tree, not just Binary Search Tree
Node2* Solution::iterative_randomized_tree_search(Node2 *root, int key)
{
	// check base case
	if (root != NULL)
		return NULL;

	std::stack<Node2 *> s1;
	s1.push(root);

	// eger boyle bir kontrol koyuyorsan bir yerlerde mutlaka pop yapmalisin.
	// ki iterasyondan cikabilesin.
	while (!s1.empty())
	{
		// We need ,first and foremost, to compare key
		// in stack the way is looking top element at a time
		// fetch top element of current stack
		Node2 *tp = s1.top();

		if (tp->key == key)
			return tp;

		// continue to iterate over
		s1.pop();

		if (tp->left != NULL)
			s1.push(tp->left);

		if (tp->right != NULL)
			s1.push(tp->right);
	}

	return NULL;
}

// This function searches & returns minimum node
// Assumption: root is a binary search tree
Node2* Solution::min (Node2 *root)
{
	if (root == NULL) return root;

	// seek always LEFT
	while (root->left != NULL)
		root = root->left;

	return root;
}

// This function searches & returns maximum node
// Assumption: root is a binary search tree
Node2* Solution::max (Node2 *root)
{
	if (root == NULL) return root;

	// seek always RIGHT
	while (root->right != NULL)
		root = root->right;

	return root;
}

// This function returns the length of linked list given as parameter,
// pointed by HEAD, recursive solution
int Solution::length (Node* head)
{
	// base case is NULLITY of given linked list
	if (head == NULL)
		return 0;

	// Spans of multiple calls of this function
	return 1 + length(head->next);

	// In a recursive way, goto end of linked list,
	// count from tail ... one by one, understand
}

/*
 * This function calculates the length of the given linked list by using tail recursion
 */
int Solution::length(Node* head, int l) // use second argument as the counter in this case
{
	// base case i) head NULL then return length, itself
	if (head == NULL) return l;

	return length (head->next, (l+1));
}

// This function reverses the linked list given as parameter,
// pointed by HEAD, iterative solution
Node* Solution::reverse(Node *head)
{
	if (head == NULL)
		return NULL;

	// local data
	Node *curr = head;
	Node *prev = NULL, *next;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev; // ilk adimda previous NULL bu noktaya dikkat et
		prev = curr; // simdi previous current noda point ediyor.

		// iterasyona devam et
		curr = next;
	}

	return prev; // now it points the tail of original list another word, reverse list.
}

// This function reverses the given linked list from position m to n
// Given m, n satisfy the following condition
// 1 <= m <= n <= length of the list
Node* Solution::reverse (Node *head, int m, int n)
{
	if (head == NULL) return NULL;
	// if ( (n - m) == 0) return head; // No modification required in the case of [1,1] or [3,3]

	// local data
	Node *curr = head, *aux = NULL, *prev = NULL, *next, *start;

	// move current by (m-1) at the begin if possible
	for (int j = 0; j < (m - 1); j++)
	{
		aux = curr;
		curr = curr->next;
	}

	// remember current
	start = curr;

	for (int i = 0; i < (n - m + 1); i++)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;

		// continue to iterate
		curr = next;
	}

	// The case of NOT movement of current, therefore auxiliary remained NULL,
	// THEN, link head.next to next and return with previous
	if (aux == NULL)
	{
		head->next = next;
		return prev;
	}
	// The case of movement of current means auxiliary points at least first node
	// THEN, link auxiliary.next to previous, (first location of current).next (start.next) to next
	// and return with previous
	else
	{
		aux->next = prev;
		start->next = next;
		return head;
	}
}

/*
 * This function rotates the given list right by k places where k non-negative
 */
Node* Solution::rotate_r (Node *head, int k)
{
	// local data
	int n = length (head, 0);

	if (n == 0 || n == 1) return head; // if head is null or contains one element

	for (int i = 0; i < (k % n); i++)
		head = rotate_r_one (head);

	return head;
}

/*
 * This function rotates the given list right by one place
 * Assumption : the list pointed by head contains at least two or more elements
 */
Node* Solution::rotate_r_one (Node *head)
{
	// defensive check
	if (head == NULL || head->next == NULL) return head;

	// local data
	Node *current = head, *prev = NULL;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}

	prev->next = NULL;
	current->next = head;

	return current;
}
// This function prints the given string in reverse order without altering the string
void Solution::print_r (char *str)
{
	if (*str)
	{
		print_r(str+1);

		// job done
		printf("%c", *str);
	}
	// base case i) 'do nothing'
}

// This function prints the singly-linked list in reverse order
void Solution::print_r (Node *head)
{
	if (head != NULL)
	{
		print_r (head->next);
		printf ("%d\t", head->key);
	}
	// base case i) do nothing
}
// This function gets the middle element of the linked list given as parameter,
// pointed by HEAD
Node* Solution::get_middle_node(Node *head)
{
	Node *first = head, *second = head;

	// The idea to put two pointer and one to move by one step while the second one to move by two step
	// When fast one reaches the end, slow one points the middle node of list
	while (second != NULL && second->next != NULL)
	{
		first = first->next; // slow pointer
		second = second->next->next; // fast pointer
	}
	// at the end of iteration, think about...
	return first;
}

// This function detects whether cycle or not in the linked list given as parameter
// pointed by HEAD
int Solution::detect_cycle(Node *head)
{
	// construct similar logic as getting middle node of linked list
	Node *first = head, *second = head;

	while (first != NULL && second != NULL && second->next != NULL)
	{
		first = first->next; // slow pointer
		second = second->next->next; // fast pointer

		// first and second points the same node, then cycle detected
		if (first == second)
			return SUCCESS;

		/*
		 * else continue the iteration
		 */
	}
	// If we reaches this point then there is no cycle since list the loop terminates w/ NULL

	return -1;
}

// This function checks whether linked list is palindrome or not given as a parameter
// pointed by HEAD
int Solution::check_palindrome(Node *head)
{
	// base case
	if (head == NULL)
		return SUCCESS;

	// local data
	std::vector<int> v;
	push_r (head, v);

	unsigned int i = 0;

	while (i < v.size())
	{
		if (v[i] != head->key)
			return -1;

		// traverse vector & list
		i = i + 1;
		head = head->next;
	}

	// If we reach at this point, the list is a palindrome
	return SUCCESS;
}

// This function pushes the key from the given singly-linked list in reverse order
// It is similar to print key in reverse order
void Solution::push_r (Node *head, std::vector<int>& A)
{
	if (head != NULL)
	{
		push_r (head->next, A);
		A.push_back(head->key);
	}
	// base case i) do nothing
}

// This function searches the target in the given sorted array
int Solution::search(const std::vector<int>& A, int first, int last, int target)
{
	// base case i)
	if (first > last)
	{
		return NOT_FOUND;
	}
	else
	{
		int mid = first + (last - first) / 2; // avoid overflow a negative value

		// base case ii)
		if (target == A[mid])
			return mid;
		else if (target > A[mid]) // continue to search in array::RIGHT
			return search(A, mid+1, last, target);
		else // continue to search in array::LEFT
			return search(A, first, mid-1, target);
	}
}

/** This function returns K-TH smallest value in a binary search tree
 *	Assume k in in valid range
 */
int Solution::k_small (Node2 *root, int k)
{
	if (root != NULL)
	{
		std::vector<int> v;
		construct_vector(root, v);
		return v[k-1];
	}
	else
		return INT_MAX;
}

// This funcion solves K-TH small problem in recursive way without using any additional data structure
int Solution::k_small(int k, Node2 *root)
{
	if (root != NULL)
	{

	}
	else
		return INT_MAX;
}

/*
 * This function constructs a vector from a binary tree based on INORDER traversal algorithm
 * @Warning : Note that this vector is sorted if given binary tree is actually binary search tree
 */
void Solution::construct_vector(Node2 *root, std::vector<int>& A)
{
	// TODO : Solve in iteration
	if (root != NULL)
	{
		construct_vector(root->left, A);

		// Instead of print out the current value, just push it to vector
		A.push_back (root->key);

		construct_vector(root->right, A);
	}
	// base case i) do nothing
}

// This function searches the maximum value in the given unsorted array
int Solution::max(const std::vector<int>& A, int first, int last)
{
	// base case
	if (first >= last) // array SZE of 1
		return A[last]; // remember at the end, you can think as leaf node, this function returns from here
	else
	{
		int mid = first + (last - first) / 2;
		return std::max ( max (A, first, mid), max (A, mid+1, last)  );
	}
}

// This function searches the maximum value in the given unsorted array (alternative)
int Solution::max(const std::vector<int>& A, int size)
{
	// base case
	if (size  == 1) // array SZE of 1
		return A[0]; // remember at the end, you can think as leaf node, this function returns from here
	else
	{
		// approach last & rest
		return std::max ( A[size-1], max (A, size-1)  );
	}
}

// This function returns the K-TH largest value in the given array
int Solution::k_largest (std::vector<int>& A, int k)
{
	// local data
	int size = A.size();

	// Actually, K-TH largest means (SIZE-K)-TH smallest, then problems turns finding (SIZE-K) smallest value in the given array
	return k_small ( (size-k + 1), A, 0, size-1);
}

// This function returns the K-TH smallest value in the given array
int Solution::k_small (int k, std::vector<int>& A, int first, int last)
{
	if (k > (last - first +1) || k < 0)
		return INT_MAX;

	// select pivot index based on lomuto's partition
	int pivotIdx = l_partition(A, first, last);

	if (k < (pivotIdx - first + 1) )
		return k_small (k, A, first, pivotIdx-1);
	else if (k == (pivotIdx - first + 1) )
		return A[pivotIdx]; // base case
	else
		return k_small (k - (pivotIdx - first + 1), A, pivotIdx+1, last);
}

// This function implements the Lomuto's partition
int Solution::l_partition(std::vector<int>& A, int p, int r)
{
	int pivot = A[r]; // select pivot as last element
	int i = p - 1;

	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= pivot)
		{
			i = i+1;
			swap (&A[i], &A[j]);
		}
	}

	swap (&A[i+1], &A[r]);
	return (i+1);
}

// This function implements the hoare's partition
int Solution::h_partition(std::vector<int>& A, int p, int q)
{
	// TODO
}

void Solution::swap (int *x, int *y)
{
	// local data O(1) In Place
	int temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * This function finds the maximum # of occurrence any number given in the list
 */

int Solution::find_maximum_occurrence (std::vector<const char *>& A)
{
	// Note : Use map in order to catch O(N) solution P.S. you will remember this line
	int size = A.size();
	std::map<const char *, int> temp; // define map onto stack

	for (int j = 0; j < size; j++)
	{
		if (temp.find(A[j]) == temp.end()) // not contain
			temp.insert(std::pair<const char *, int> (A[j], 1) );
		else // already contain
			temp.find(A[j])->second = temp.find(A[j])->second + 1; // simply increment the occurrence
	}

	// you know map already sorted, reach out with the iterator begin
	return temp.begin()->second;
}

/*
 * This function prints pair from given array whose sum is equal the the given sum
 */
void Solution::print_pair_sum (std::vector<int>& A, int sum)
{
	// Note: similar logic as in the function finding maximum occurrence problem expected solution complexity : O (N)
	int size = A.size();
	std::unordered_map<int, int> temp; // define map onto stack

	// construct pairs by making key as vector value and value as vector index, <key, value>
	for (int i = 0; i < size; i++)
		temp.insert(std::pair<int, int> (A[i], i) );

	for (int j = 0; j < size; j++)
	{
		int diff = (sum - A[j]); // now problems turn into seeking DIFF in map

		// OK, key,value pair in fact a,b where a+b = sum in order words, sum-a = b
		if (temp.find(diff) != temp.end()) // contain
			printf ("pair as sum %d, (<%d, %d>) \n", sum, diff, A[j]);
	}
}
