/**
Accelerated C++, Exercise 8-2, 8_2.cpp

Implement the following library algorithms, which we used in Chapter 6 and
described in �6.5/121. Specify what kinds of iterators they require. Try to minimize the
number of distinct iterator operations that each function requires. After you have
finished your implementation, see �B.3/321 to see how well you did.

    equal(b, e, d)                search(b, e, b2, e2)
    find(b, e, t)                 find_if(b, e, p)
    copy(b, e, d)                 remove_copy(b, e, d, t)
    remove_copy_if(b, e, d, p)    remove(b, e, t)
    transform(b, e, d, f)         partition(b, e, p)
    accumulate(b, e, t)

*/

#include "stdafx.h"
#include "8_2.h"

#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <exception>
using std::domain_error;

#include <iterator>

template <class X>
string print_vector(const vector<X>vec)
{
  if (vec.size() <= 0)
    throw domain_error("Empty vector");

  stringstream ss;

  ss << "[ " << vec[0];
  
  for (vector<X>::size_type i = 1; i < vec.size(); i++)
    ss << ", " << vec[i];

  ss << " ]";

  return ss.str();
}

int ex8_2()
{
  vector<int> vec1 = { 10, 25, 35, 40, 50 };
  vector<int> vec2 = { 10, 27, 35, 40, 50 };
  vector<int> vec3 = { 10, 25, 35, 40, 50 };

  cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec2)
    << " ? " << algorithms::equal(vec1.begin(), vec1.end(), vec2.begin()) << endl;
  cout << "Is " << print_vector(vec1) << " equal to " << print_vector(vec3)
    << " ? " << algorithms::equal(vec1.begin(), vec1.end(), vec3.begin()) << endl;

  cout << "Find 35 in " << print_vector(vec1) << " => " << *algorithms::find(vec1.begin(), vec1.end(), 35) << endl;

  return 0;
}