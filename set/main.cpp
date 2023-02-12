#include <iostream>
#include<vector>

#include "set.hpp"
#include "rbTree.hpp"


#define	_set	 			ft::set
#define	_is_integral 		ft::is_integral
#define	_enable_if 			ft::enable_if
#define	_pair 				ft::pair
#define	_make_pair 			ft::make_pair
#define	_lexicographical	ft::lexicographical_compare
#define	_equal				ft::equal



int main()
{
    // ft :: rbTree<int, std::less<int>, std::allocator<int> > tree;
    // _set<int> st;
    // std::vector<int> v;

    
    // _pair<_set<int>::iterator , bool> pair = st.insert(7);
    // // _set<int>::iterator it = st.begin();
    // // v.push_back(*it);

    // _pair<_set<int>::iterator , bool> pair2 = st.insert(9);
    // // _set<int>::iterator it2 = pair.first;
    // //  v.push_back(*it2);
    // // v.push_back(*(pair2.first));
    // // v.push_back(pair2.second);
    // st.print();
    // for (int i = 0; i < 50 * 10000; ++i) {
    //     std::cout<<i<<std::endl;
    //     if(i == 20)
    //     {
            
    //         st.print();
    //         break;
    //     }
    //     st.insert(i);
        
    // }
    // st.print();



    ft::set<int> test;
    test.insert(8);
    test.insert(18);
    test.insert(5);
    test.insert(15);
    test.insert(17);
     test.insert(25);
     test.insert(40);

    // test.insert(80);
    
    // //  test.insert(30);
    // //  test.insert(29);

    test.print();
   


//   test.insert(1);
//     test.insert(2);
//     test.insert(3);
//     test.insert(4);
//       test.insert(5);
//      test.insert(6);
//      test.insert(7);
//      test.insert(8);
//      test.insert(9);


    //  test.insert(5);

    
    
    // tree.leftRotate((tree.insert(17))->parent);
    // test.print();
    //  test.insert(25);
    //  test.insert(40);
    //  test.insert(83);
    //  test.insert(5);

    // std :: cout << test.empty() << std::endl;
    
   

    // std :: cout <<"size is: "<< test.size() << std::endl;
    // std :: cout << test.empty() << std::endl;
    // std :: cout << test.size() << std::endl;


    // if (it == test.end())
    // {
    //     std::cout << "cant find it " << std::endl;
    // }
    // else
    //     std::cout << "key found " << std::endl;
    
    

}