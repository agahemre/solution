/*
 *  @name: Driver.cpp
 *  @author: EA
 */

#include "Solution.h"
#include <vector>
#include <random>
#include <algorithm>

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

vector<int> construct_demo_vector_custom_sort()
{
	vector<int> v1;
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(10);
	v1.push_back(9);
	v1.push_back(8);
	v1.push_back(3);
	v1.push_back(6);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(13);
	v1.push_back(9);
	v1.push_back(7);
	v1.push_back(6);

	return v1;
}

vector<const char *> construct_demo_vector_v2()
{
	vector<const char *> v1;
	v1.push_back("canan");
	v1.push_back("emrecan");
	v1.push_back("emrecan");
	v1.push_back("emma");
	v1.push_back("canan");
	v1.push_back("canan");
	v1.push_back("burcu");
	v1.push_back("canan");
	v1.push_back("emrecan");
	v1.push_back("cem");
	v1.push_back("emrecan");
	v1.push_back("eren");
	v1.push_back("aysen");
	v1.push_back("canan");
	v1.push_back("canan");
	v1.push_back("emrecan");
	v1.push_back("cem");
	v1.push_back("canan");
	v1.push_back("emrecan");
	v1.push_back("anil");

	return v1;
}

int main()
{
	vector<int> v = construct_demo_vector();
	vector<int> c_sort = construct_demo_vector_custom_sort();
	vector<const char *> v2 = construct_demo_vector_v2();
	int sze = v.size();
	const int target = 71;
	const int sum = 45;
	int k = 14;
	int new_k = sze-k+1;
	int index = solution::search(v, 0, sze-1, target);
	char word[] = "1234567890"; // sample
	string s("anilella");
	string s0("anil");
	string str("aca");
	// string a("abc");
	 string a("stuvwx");
	// string w("jdzsnpejkyqktrdlljfuozlfsvrhqrwgtojnxllzmbfvoexxxttzcbprwzyztsovcxootxoswbffcokhtosfvn");
	string b("abc");
	//string b("def");
	string w("keyhbmeknckfavrpqyyfjxjjmivtsftikovkcdcwefctqrqjryhtlcvstm");

	// debug purpose
	printf ("The target index -> %d\n", index);
	printf ("The max value -> %d\n", solution::max(v, 0, sze-1) );
	printf ("The max value (last & rest) -> %d\n", solution::max(v, sze) );
	printf ("The reverse of the given array -> ");

	// Shuffle vector before test
	auto rng = std::default_random_engine {};
	std::shuffle(v.begin(), v.end(), rng);

	printf ("The k-th (%d) smallest value -> %d\n", k, solution::k_small(k, v, 0, sze-1) );
	printf ("The k-th (%d) largest value -> %d\n", new_k, solution::k_largest(v, new_k) );
	printf ("The maximum number of occurrence of word -> %d\n", solution::find_maximum_occurrence(v2) );
	solution::print_pair_sum(v, sum);
	printf ("Prints characters in reverse order -> "); solution::print_r (word);
	printf ("\n");
	printf ("Compare %s and %s, result -> %d\n", s.c_str(), s0.c_str(), solution::compare(s, s0) );
	printf ("Compare %s and %s, result -> %d\n", s.c_str(), s0.c_str(), s.compare(s0) ); // TEST WITH BUILT-IN FUNCTION
	printf ("Check given string %s is whether palindrome or not, result -> %d\n", str.c_str(), solution::is_palindrome(str) );
	printf ("Merge given string %s and %s, result -> %s\n", a.c_str(), b.c_str(), solution::merge_str(a, b).c_str() );

	for (auto const& i : c_sort)
		printf ("%d ", i);
	printf ("\nCustom sort performed\n");
	solution::custom_sort(c_sort);

	for (auto const& j : c_sort)
		printf ("%d ", j);
	printf("\n");

	return solution::SUCCESS;
}
