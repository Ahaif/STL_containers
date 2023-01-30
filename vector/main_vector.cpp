#include "vector.hpp"
// #include "iterator.hpp"
#include <vector>
// #include<iterator>
// using namespace ft;

int main()
{

    
    ft :: vector<int> real;
    real.push_back(10);
    real.push_back(20);
    real.push_back(30);
    real.push_back(40);
    real.push_back(50);

   std::cout<<"---------------Iterators check----------\n";
    ft :: vector<int> :: iterator test = real.begin();
    ft :: vector<int> :: iterator iter;
    std::cout << "Iterator default constructor pass\n";
    ft :: vector<int> :: iterator iter1(test);
    std::cout <<"Iterator copy constructor value should be 10: " << *iter1<<std::endl;
    iter1++;
    iter1--;
    std::cout << "Iterator incr and decr pass, value should be equal to 10: "<<*iter1<<std::endl;
    std::cout<<"----------------------------\n";

    iter1 += 2;
     std::cout <<"Iterator + operator passe value should be 30: " << *iter1<<std::endl;
     iter1 -= 2;
     std::cout <<"Iterator - operator operator passe value should be 10: " << *iter1<<std::endl;

    std::cout<<"----------------------------\n";
     iter = iter1 + 2;


     std::cout <<"Iterator + advance itr passe value should be 30: " << *iter<<std::endl;
     iter1 = iter - 2;
     std::cout <<"Iterator - operator member function value should be 10: " << *iter1<<std::endl;
     int n = iter - test;
     std::cout <<"Iterator - distance operator passe value should be 2: " << n<<std::endl;
    std::cout<<"----------------------------\n";
    iter + 1;
    iter - 1;
    std::cout <<"Iterator ARTH +- itr passe value should be 30: " << *iter<<std::endl;

    std::cout<<"\n---------------Reverse Iterators check----------\n";

    ft :: vector<int> fake(real);

    ft :: vector<int> :: reverse_iterator it_rev = fake.rbegin();
    // std ::cout<<"rbegin is: " << *it_rev << std::endl;
    std::cout<< "Elements in reverse order: " << std ::endl;
    while(it_rev != fake.rend())
    {
        
        std::cout<<*it_rev;
        ++it_rev;

    }
  
    std::cout<<"\n---------------Additional check with rev iterator----------\n";
    std::cout<<"Member function in VECTOR: rbegin, rend, *, ++ , != \n";

    std::cout<<"\n---------------Vector check ----------\n";
    std::cout<<"\n---------------constructors ----------\n";
    std::cout<<"---------------vector default constructor  ----------\n";
    std::cout<<"---------------vector copy constructor     ----------\n";
    ft :: vector<int> check(8, 50);
    ft :: vector<int> :: iterator it = check.begin();
    ft :: vector<int> :: iterator it1 = check.end();
    ft :: vector<int> check2(it,it1);

    std::cout<<"size should be 8: "<< check.size()<<std::endl;
    std::cout<<"size should be 8: "<< check2.size()<<std::endl;

    std::cout<<"---------------vector constructor size, value done  ----------\n";
    std::cout<<"---------------vector constructor iterator range done  ----------\n";
    ft::vector<int> third = check;
    std::cout<<" = operator size should be 8: "<< third.size()<<std::endl;



    third.assign(6, 10);
    std::cout<<" assign vector size should be 6: "<< third.size()<<std::endl;
    third.assign(check.begin(), check.end()-3);
    std::cout<<" assign with iter vector size should be 5: "<< third.size()<<std::endl;


    third.insert(third.begin(), 5);
    std::cout<<" insert vector size should be 6: "<< third.size()<<std::endl;

    third.insert(third.begin(), 3, 10);
    std::cout<<" insert vector size should be 9: "<< third.size()<<std::endl;

    third.insert(third.begin(), third.begin(),third.end());
    std::cout<<" insert with iterator range vector size should be 18: "<< third.size()<<std::endl;

    third.pop_back();
    third.pop_back();
    third.pop_back();
    std::cout<<" pop_back check vector size should be 15: "<< third.size()<<std::endl;


    ft::vector<int> fourth;
    fourth.swap(third);
    std::cout<<" swap check vector size should be 15: "<< fourth.size()<<std::endl;


    third.clear();
    std::cout<<" clear vector size should be 0: "<< third.size()<<std::endl;












   
}