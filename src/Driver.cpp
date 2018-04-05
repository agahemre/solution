/*
 *  @name: Driver.cpp
 *  @author: EA
 */

#include "Solution.h"
#include <vector>
#include <random>
#include <algorithm>

#define SUCCESS 8 // give any non integer value

using namespace std;

vector<int> construct_demo_vector()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(10);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(18);
	v1.push_back(19);
	v1.push_back(21);
	v1.push_back(24);
	v1.push_back(37);
	v1.push_back(40);
	v1.push_back(45);
	v1.push_back(71);

	return v1;
}

vector<const char *> construct_demo_vector_v2()
{
	vector<const char *> v1;
	v1.push_back("Emrecan");
	v1.push_back("Eren");
	v1.push_back("Emrecan");
	v1.push_back("Emma");
	v1.push_back("Canan");
	v1.push_back("Canan");
	v1.push_back("Burcu");
	v1.push_back("Emrecan");
	v1.push_back("Cem");
	v1.push_back("Emrecan");
	v1.push_back("Eren");
	v1.push_back("Aysen");
	v1.push_back("Emrecan");
	v1.push_back("Cem");
	v1.push_back("Canan");
	v1.push_back("Emrecan");
	v1.push_back("Anil");

	return v1;
}

int main()
{
	Solution solution;
	vector<int> v = construct_demo_vector();
	vector<const char *> v2 = construct_demo_vector_v2();
	int sze = v.size();
	const int target = 71;
	const int sum = 45;
	int k = 14;
	int new_k = sze-k+1;
	int index = solution.search(v, 0, sze-1, target);
	char word[] = "1234567890"; // sample
	string s("01");
	string s0("1");

	// debug purpose
	printf ("The target index -> %d\n", index);
	printf ("The max value -> %d\n", solution.max(v, 0, sze-1) );
	printf ("The max value (last & rest) -> %d\n", solution.max(v, sze) );
	printf ("The reverse of the given array -> ");

	// Shuffle vector before test
	auto rng = std::default_random_engine {};
	std::shuffle(v.begin(), v.end(), rng);

	printf ("The k-th (%d) smallest value -> %d\n", k, solution.k_small(k, v, 0, sze-1) );
	printf ("The k-th (%d) largest value -> %d\n", new_k, solution.k_largest(v, new_k) );
	printf ("The maximum number of occurrence of word -> %d\n", solution.find_maximum_occurrence(v2) );
	solution.print_pair_sum(v, sum);
	printf ("Prints characters in reverse order -> "); solution.print_r (word);
	printf ("\nCompare %s and %s, result -> %d\n", s.c_str(), s0.c_str(), solution.compare(s, s0) );
	printf ("\nCompare %s and %s, result -> %d\n", s.c_str(), s0.c_str(), s.compare(s0) ); // TEST WITH BUILT-IN FUNCTION

	return SUCCESS;
}
