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


// std::vector<int> std_test()
// {
//            std::vector<int> v;
//            std::set<int>st;

   
//     st.insert(5);
//     st.insert(3);
//     st.insert(7);
//     typename std::set<int>::reverse_iterator rit = st.rbegin();
//     typename std::set<int>::reverse_iterator rit2 = st.rend();
//     v.push_back(*rit);
//     std::cout<<"passed"<<std::endl;
//     std::cout<<"rit std "<< *rit2 << "|"<<std::endl;
//     rit++;
//     rit2--;
//     v.push_back(*rit);
//     v.push_back(*rit2);
//     rit++;
//     v.push_back(*rit == *rit2);
//     v.push_back(rit == rit2);
//     rit2--;
//     v.push_back(*rit);
//     v.push_back(*rit2);
//     v.push_back(*rit2 > *rit);
//     v.push_back(*rit2 < *rit);
//     v.push_back(*(--rit));
//     v.push_back(*(++rit2));
//     v.push_back(*(rit--));
//     v.push_back(*(rit2++));
//     return v;

// }

// void run_uni_test(std::vector<int> myTest, std::vector<int> stdTest)
// {
//     if (myTest.size() != stdTest.size())
//         std::cout<<"size issue"<<std::endl;
//     for(int i = 0; i < stdTest.size(); i++)
//     {
//         if(myTest[i] != stdTest[i])
//         {
//                 std::cout<<"my vec test | std vec:"<<std::endl;
//                 for(int j = 0; j<=i; j++)
//                 {
//                     std::cout<<myTest[j]<<"|";
//                     std::cout<<stdTest[j]<<"|"<<std::endl;

                    
//                 }
//                 std::cout<<"test case " << i << " is diffrent: " << myTest[i]<< stdTest[i] <<std::endl;
                

//         }
            
//     }

// }

int main()
{
    
    std::vector<int> v;
    _set<int>st;
    // std::set<int>st;

    for(int i = 0; i < 15; i++)
    {
        st.insert(i);
    }

    
     st.print();
    //  st.erase(14);
    //   st.print();

       st.erase(0);

    std::cout<<"map after erase: "<<std::endl;

    st.print();
    




       



    
  
   
   


   


    //  for(; i < 30 * _ratio ; i++)
    // {
    //     // std::cout<<"i is: "<<i<<std::endl;
    //     st.erase(i);
    // }
 


}



    
