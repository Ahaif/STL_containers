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
    std::vector<int>vector;
   

    std::vector<int> tmp, tmp2;

    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
  
  
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());

    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());


    return v;
}




int main()
{

    _vector<int>vector;
    std::vector<int> v;
 


    _vector<int> tmp, tmp2;
    vector.assign(3, 3);
    tmp.assign(4000 * _ratio, 1);
    tmp2.assign(4 * _ratio, 1);
  

    vector.assign(tmp.begin(), tmp.end());
    
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());

    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());



    run_uni_test(v, std_test());
  
    
}