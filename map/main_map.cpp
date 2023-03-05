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



void run_uni_test( std::vector<int> v1,  std::vector<int> v2)
{
    for(int i = 0; i< v2.size(); i++)
    {
        if(v1[i] != v2[i])
            std::cout << "different case" << i << std::endl;
    }
    std::cout<<"test passed successful"<< std::endl;

}





std::vector<int>    reverse_iterators_test_std() {
    std::vector<int> v;

    std::map<int, int> mp;
    mp.insert(std::make_pair(5, 5));
    mp.insert(std::make_pair(3, 3));
    mp.insert(std::make_pair(7, 7));
    typename std::map<int, int>::reverse_iterator rit = mp.rbegin();
    typename std::map<int, int>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);
    return v;
}



int main() {

    std::vector<int> v;

    _map<int, int>mp;
    mp.insert(_make_pair(5, 5));
    mp.insert(_make_pair(3, 3));
    mp.insert(_make_pair(7, 7));
    typename _map<int, int>::reverse_iterator rit = mp.rbegin();
    typename _map<int, int>::reverse_iterator rit2 = mp.rend();
    v.push_back(rit->first);
    rit++;
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    rit++;
    v.push_back(*rit == *rit2);
    rit2--;
    v.push_back(rit->first);
    v.push_back(rit2->first);
    v.push_back(*rit2 > *rit);
    v.push_back(*rit2 < *rit);
    v.push_back((--rit)->first);
    v.push_back((++rit2)->first);
    v.push_back((rit--)->first);
    v.push_back((rit2++)->first);

    // run_uni_test(v, reverse_iterators_test_std());



}