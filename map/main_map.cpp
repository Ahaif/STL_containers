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




void run_uni_test(std::vector<int> myTest, std::vector<int> stdTest)
{
    if (myTest.size() != stdTest.size())
        std::cout<<"size issue"<<std::endl;
   
            std::cout<<"std size: "<<stdTest.size()<<std::endl;
            std::cout<<"myTest size: "<<myTest.size()<<std::endl;
                std::cout<<"my vec test | std vec:"<<std::endl;
                for(int j = 0; j < stdTest.size(); j++)
                {
                    std::cout<<myTest[j]<<"|";
                    std::cout<<stdTest[j]<<"|"<<std::endl;

                    
                }
      
    std::cout<<"passed unitest"<<std::endl;
}




std::vector<int> std_test() {

        std::vector<int> v;
        std::map<int, int> mp;
       for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(std::make_pair(i, j));
    std::map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    std::map<int, int>::iterator it4 = mp.begin();
  
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4);
  
    v.push_back(mp.size());
    std::map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(std::make_pair(i, j));
    std::map<int, int32_t>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    ittest = mp2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
    std::map<int, int>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }


    return v;

}



int main() {

    std::vector<int> v;
    _map<int, int>mp;
    for (int i = 0, j = 0; i < 30 * _ratio; ++i, ++j)
        mp.insert(_make_pair(i, j));
    _map<int, int>::iterator it = mp.begin();
    v.push_back(it->first);
    mp.erase(it);
    v.push_back(mp.size());
    it = mp.begin();
    mp.erase(++it);
    v.push_back(mp.size());
    it = mp.begin();
    v.push_back(it->first);
    _map<int, int>::iterator it4 = mp.begin();
  
    for (; it4 != mp.end(); it4 = mp.begin())
        mp.erase(it4);
  
    v.push_back(mp.size());
    _map<int, int> mp2;
    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp2.insert(_make_pair(i, j));
    _map<int, int32_t>::iterator ittest = mp2.begin();
    for (int i = 0; i < 2; ++i) ittest++;
    mp2.erase(ittest);
    ittest = mp2.begin();
    for (int i = 0; i < 5; ++i) ittest++;
    mp2.erase(ittest);
    _map<int, int>::iterator it3 = mp2.begin();
    for (; it3 != mp2.end(); ++it3) {
        v.push_back(it3->first);
        v.push_back(it3->second);
    }

    run_uni_test(v, std_test());

    return(0);



}