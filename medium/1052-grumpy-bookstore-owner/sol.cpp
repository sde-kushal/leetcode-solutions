#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:
        int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
            int nonGrumpyHrs = 0;
            int maxGrumpy = 0, localGrumpy = 0;
            int right = 0;
    
            for(;right<minutes;right+=1) {
                if(grumpy[right] == 0)  nonGrumpyHrs += customers[right];
                else                    localGrumpy += customers[right];
            }
    
            maxGrumpy = localGrumpy;
    
            for(;right<customers.size();right+=1) {
                if(grumpy[right] == 0)  nonGrumpyHrs += customers[right];
                else                    localGrumpy += customers[right];
    
                if(grumpy[right-minutes])
                    localGrumpy -= customers[right-minutes];
                
                maxGrumpy = max(maxGrumpy, localGrumpy);
            }
    
            return nonGrumpyHrs + maxGrumpy;
        }
    };