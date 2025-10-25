#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(const int a, const int b) const {
            return a > b;
        }
    };

public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        Compare compare;
        sort(happiness.begin(), happiness.end(), compare);

        long long maxHappiness = 0;
        int temp;
        
        for(int i=0; i<k; i+=1) {
            if(i > happiness[i])    temp = 0;
            else                    temp = happiness[i] - i;
            
            maxHappiness += temp;
        }

        return maxHappiness;    
    }
};