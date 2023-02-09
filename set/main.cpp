#include <iostream>

#include "set.hpp"
#include "rbTree.hpp"





int main()
{
    // ft :: rbTree<int, std::less<int>, std::allocator<int> > tree;

    ft :: set<int> test;

    // ft :: set<int> :: iterator it = test.find(10);
    // std :: cout << test.empty() << std::endl;
    // std :: cout << test.size() << std::endl;

    test.clear();
    test.insert(8);
    test.insert(18);
    test.insert(5);
    test.insert(15);
    test.insert(17);
    // tree.clear();
    // tree.insert(8);
    // tree.insert(18);
    // tree.insert(5);
    // tree.insert(15);
    // // tree.insert(17);
    
    // tree.leftRotate((tree.insert(17))->parent);
    test.print();
    //  test.insert(25);
    //  test.insert(40);
    //  test.insert(83);
    //  test.insert(5);

    // std :: cout << test.empty() << std::endl;
    
   

    std :: cout <<"size is: "<< test.size() << std::endl;
    // std :: cout << test.empty() << std::endl;
    // std :: cout << test.size() << std::endl;


    // if (it == test.end())
    // {
    //     std::cout << "cant find it " << std::endl;
    // }
    // else
    //     std::cout << "key found " << std::endl;
    
    

}