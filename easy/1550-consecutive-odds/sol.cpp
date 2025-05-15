#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consecutiveOdds = 0;

        for(int i=0;i<arr.size();i+=1) {
            if(arr[i]%2==0) consecutiveOdds = 0;
            else {
                consecutiveOdds += 1;
                if(consecutiveOdds == 3)
                    return true;
            }
        }

        return false;
    }
};