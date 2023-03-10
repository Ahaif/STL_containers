#include <iostream>
#include<vector>
#include<set>

#include "set.hpp"
#include "rbTree.hpp"


#define	_set	 			ft::set
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal




// template <class T, class C>
// void fillSet(_set<T, C> &mp) {
   
// 	mp.insert(16);
// 	mp.insert(8);
// 	mp.insert(23);
// 	mp.insert(7);
// 	mp.insert(19);
// 	mp.insert(29);
// 	mp.insert(41);
// 	mp.insert(4);
// 	mp.insert(11);
    
// }

#define _ratio 10000


std::vector<int> std_test()
{
     std::set<int>st;
    std::vector<int> v;
    // v.push_back(st.erase(3));
    // for (int i = 0; i < 10; ++i)
    //     st.insert(i);
    //  std::set<int>::iterator it = st.begin();
    // v.push_back(*it);
    // v.push_back(st.erase(-5));
    // v.push_back(st.size());
    // v.push_back(st.erase(0));
    // v.push_back(st.size());
    //  std::set<int>::iterator it4 = st.begin();

    // for (; it4 != st.end(); it4 = st.begin())
    //     st.erase(*it4);
  
    // v.push_back(st.erase(10 - 1));
    // v.push_back(st.size());
    std::set<int> st2;
    for (int i = 0; i < 10 ; ++i)
        st2.insert(i);
    // st2.erase(2);
    st2.erase(7);
     std::set<int>::iterator it3 = st2.begin();
    for (; it3 != st2.end(); it3++) {
        v.push_back(*it3);
    }
    return v;
   

}

void run_uni_test(std::vector<int> myTest, std::vector<int> stdTest)
{
    if (myTest.size() != stdTest.size())
        std::cout<<"size issue"<<std::endl;
    for(int i = 0; i < stdTest.size(); i++)
    {
        if(myTest[i] != stdTest[i])
        {
                std::cout<<"my vec test | std vec:"<<std::endl;
                for(int j = 0; j<=i; j++)
                {
                    std::cout<<myTest[j]<<"|";
                    std::cout<<stdTest[j]<<"|"<<std::endl;

                    
                }
                std::cout<<"test case " << i << " is diffrent: " << myTest[i]<< stdTest[i] <<std::endl;
                

        }
            
    }

}

int main()
{

    std::vector<int> v;
    _set<int>st;
    for (int i = 0; i < 50 * _ratio; ++i)
        st.insert(i);

    
    std::cout<<"st begin is: "<<*(st.begin())<<std::endl;
    std::cout<<"st end is: "<<*(--st.end())<<std::endl;


   
    st.erase(st.begin(), --st.end());
  
    // v.push_back(*(st.begin()));


}



    
