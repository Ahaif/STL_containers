#include "stack.hpp"

using namespace ft;

int main()
{


  vector<int> myvector (2,200);        // vector with 2 elements

  stack<int> first;                    // empty stack

  stack<int,vector<int> > third;  // empty stack using vector
  stack<int,vector<int> > fourth (myvector);


  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

//   stack<int> mystack;

//   mystack.push(10);
//   mystack.push(20);

//   mystack.top() -= 2;

//   std::cout << "mystack.top() is now " << mystack.top() << '\n';


  stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

 

}