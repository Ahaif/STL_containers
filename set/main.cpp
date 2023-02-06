#include <iostream>

#include "set.hpp"






int main()
{
    ft :: set<int> test;

    // ft :: set<int> :: iterator it = test.find(10);
    // std :: cout << test.empty() << std::endl;
    // std :: cout << test.size() << std::endl;

    
    test.insert(11);
    test.insert(7);
    test.insert(15);
     test.insert(5);
    
    // std :: cout << test.empty() << std::endl;
    std :: cout << test.size() << std::endl;
    // test.clear();
    test.print();
    // std :: cout << test.empty() << std::endl;
    // std :: cout << test.size() << std::endl;


    // if (it == test.end())
    // {
    //     std::cout << "cant find it " << std::endl;
    // }
    // else
    //     std::cout << "key found " << std::endl;
    
    

}