/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> coll;

    // insert elements from 20 to 40
    for (int i=20; i<=40; ++i) {
        coll.push_back(i);
    }

    // find position of element with value 3
    // - there is none, so pos3 gets coll.end()
    auto pos3 = find (coll.begin(), coll.end(),    // range
                      3);                          // value
    
    // reverse the order of elements between found element and the end
    // - because pos3 is coll.end() it reverses an empty range
    reverse (pos3, coll.end());

    // find positions of values 25 and 35
    list<int>::iterator pos25, pos35;
    pos25 = find (coll.begin(), coll.end(),  // range
                  25);                       // value
    pos35 = find (coll.begin(), coll.end(),  // range
                  35);                       // value

    // print the maximum of the corresponding range
    // - note: including pos25 but excluding pos35
    cout << "max: " << *max_element (pos25, pos35) << endl;

    // process the elements including the last position
    cout << "max: " << *max_element (pos25, ++pos35) << endl;
}
