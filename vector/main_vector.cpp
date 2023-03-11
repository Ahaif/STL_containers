#include "vector.hpp"
#include "iterator.hpp"
#include <vector>

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


#define _ratio 10000



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





std::vector<int> std_test() {
    std::vector<int> v;
    std::vector<int>vector;

    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);
    
    
    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
 

    v.push_back(*(vector.begin() + 82 * _ratio));
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    return v;
}




int main()
{

      std::vector<int> v;
    
    _vector<int>vector;
 
    for (int i = 0; i < 9900 * _ratio; ++i)
        vector.push_back(i);

    
    

    v.push_back(*(vector.erase(vector.begin() + 8 * _ratio, vector.end() - 1500 * _ratio)));
 

    // v.push_back(*(vector.begin() + 82 * _ratio));
    // v.push_back(vector.size());
    // v.push_back(vector.capacity());

    // run_uni_test(v, std_test());
  
    
}