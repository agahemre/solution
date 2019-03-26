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

vector<char> construct_character_vector()
{
    vector<char> vc;
    vc.push_back('Z');
    vc.push_back('H');
    vc.push_back('G');
    vc.push_back('F');
    vc.push_back('E');
    vc.push_back('D');
    vc.push_back('C');
    vc.push_back('B');
    vc.push_back('A');

    return vc;
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
    vector<char> vc = construct_character_vector();
    int sze = v.size();
    int c_sze = vc.size();
    const int target = 37;
    const int sum = 45;
    const int rotation = 102;
    int k = 6;
    int new_k = sze-k+1;
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
    const int days = 3;
    vector<int> Cells = {1, 0, 0, 0, 0, 1, 0, 0};
    for (auto const& cell : Cells) printf("%d\t", cell);
    printf("\n");
    printf("Call amazing automata after %d days:\n", days);
    solution::amazingAutomata(Cells, days);
    for (auto const& cell : Cells) printf("%d\t", cell);
    printf("\n");

    printf ("The k-th (%d) smallest value -> %c\n", 8, solution::k_smallest(8, vc, 0, c_sze-1, HOARE) );
    printf ("The k-th (%d) smallest value -> %c\n", 8, solution::k_smallest(8, vc, 0, c_sze-1, LOMUTO) );
    printf ("The k-th (%d) largest value -> %c\n", 2, solution::k_largest(vc, 2, HOARE) );
    printf ("The k-th (%d) largest value -> %c\n", 2, solution::k_largest(vc, 2, LOMUTO) );

    // debug purpose
    printf ("The target -> %d, and its index -> %d\n", target, solution::search(v, 0, sze-1, target));
    printf ("The max value -> %d\n", solution::max(v, 0, sze-1) );
    printf ("The max value (last & rest) -> %d\n", solution::max(v, sze) );
    printf ("Result array after shuffle operation\n");

    // Shuffle vector before test
    auto rng = std::default_random_engine {};
    std::shuffle(v.begin(), v.end(), rng);

    for (auto const& e : v) printf ("%d\t", e);
    printf("\n");
    printf ("Reverse of array, and apply left rotate %d times:\n", rotation);
    solution::reverse (v, 0, v.size()-1);
    solution::rotate (v, rotation, CCW);

    for (auto const& e : v) printf ("%d\t", e);
    printf("\n");
    printf ("The k-th (%d) smallest value -> %d\n", k, solution::k_smallest(k, v, 0, sze-1, HOARE) );
    printf ("The k-th (%d) smallest value -> %d\n", k, solution::k_smallest(k, v, 0, sze-1, LOMUTO) );
    printf ("The k-th (%d) largest value -> %d\n", new_k, solution::k_largest(v, new_k, HOARE) );
    printf ("The k-th (%d) largest value -> %d\n", new_k, solution::k_largest(v, new_k, LOMUTO) );
    printf ("The number of maximum occurrences amongst number[s] -> %d\n", solution::find_max_occur(c_sort) );
    printf ("The number of maximum occurrences amongst word[s] -> %d\n", solution::find_max_occur(v2) );
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

    return SUCCESS;
}
