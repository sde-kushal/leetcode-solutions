#include <vector>
using namespace std;

class ProductOfNumbers {
    private:
      vector<int> prods;
    
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            for(int i=prods.size()-1;i>=0;i-=1) {
              if(prods[i]==0)
                break;
              prods[i] *= num;
            }
    
            prods.push_back(num);    
        }
        
        int getProduct(int k) {
            return prods[prods.size() - k];
        }
    };