#include <iostream>
#include "map.hpp"
// #include <string>
// #include <string_view>
using namespace ft;
 

 
int main()
{

    std :: cout << "-----Constructors check-----" << std :: endl; 
    map<std :: string, int> mymap;
		mymap["abde"] = 100;
		mymap["haif"] = 200;
		mymap["test"] = 300;
		// show content:
		// for (map<std :: string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		// 	std::cout << it->first << " => " << it->second << '\n';
		std::cout << "mymap.size() is " << mymap.size() << '\n';

    map<std :: string, int> second(mymap.begin(), mymap.end());
    std::cout << "my second map.size() is " << second.size() << '\n';

    map<std :: string, int> third(second);
    std::cout << "my third map.size() is " << third.size() << '\n';

    //operator = check 
    map<std :: string, int> forth = third;
    std::cout << "my forth map.size() is " << forth.size() << '\n';
    // acces elem check 
    std :: cout << "-----Acces elem check -----" << std :: endl; 
    std :: cout << "elem in thi case is " << forth["haif"] << std :: endl;
    std :: cout << "-----Iterators check -----" << std :: endl; 
  //  map<std :: string, int> :: iterator ite = forth.end();
  // std::cout << ite->first << " => " << ite->second << '\n';
  for (map<std :: string, int>::iterator it = forth.begin(); it != forth.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
  // ite = forth.end();
  // std::cout << ite->first << " => " << ite->second << '\n';

  // ANOTHER RECHECK FOR REVERSE ITERATORS 
  std :: cout << "-----Capacity elem check -----" << std :: endl; 
  std::cout << forth.empty() << '\n';  
  std::cout << forth.size() << '\n';  
  //RECHECK MAX SIZE

    forth.clear();
    std::cout << forth.size() << '\n'; 

  std :: cout <<"---------insert check-------" << std :: endl;
  map<int, int> mp;
 
		for (int i = 0; i < 5; i++)
		{
			mp.insert(make_pair(i, i * 2));
		}
    std :: cout << mp.size() << std :: endl;
	// 	// // // mp.print();
		 map<int, int>::iterator it = mp.begin();
    mp.insert(it, make_pair(7, 9));
		// std::cout << it->first << " " << it->second <<  std::endl;
		// // mp.print();
    
		for (; it != mp.end(); it++)
		{
			std::cout << it->first << " " << it->second << std::endl;
		}
}

