#include <iostream>

#define	_vector 			ft::vector
#define	_stack	 			ft::stack
#define	_map 				ft::map
#define	_set	 			ft::set
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal
#include "map.hpp"
#include<map>
#include <vector>


#define _ratio 10000






int main() {

    std::vector<int> v;
    _map<int, int>mp;
    int j;
    v.push_back(mp.erase(3));
    for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
     _map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    v.push_back(mp.erase(-5));
    v.push_back(mp.size());
    v.push_back(mp.erase(0));
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
     _map<int, int>::iterator it4 = mp.begin();
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4->first);
    v.push_back(mp.erase(30 * _ratio - 1));
    v.push_back(mp.size());
    _map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(_make_pair(i, j));
    mp2.erase(2);
    mp2.erase(7);
    typename _map<int, int>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }

    // run_uni_test(v, reverse_iterators_test_std());



}