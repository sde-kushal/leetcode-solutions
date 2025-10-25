#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(const int a, const int b) const {
            auto numLen = [](int n) {
                n = abs(n);
                if(n == 0)  return 1;
                int digits = 0;
                
                while(n>0) {
                    digits += 1;
                    n /= 10;
                }
                return digits;
            };

            if(to_string(a)[0] == to_string(b)[0])
                return a*pow(10, numLen(b))+b > b*pow(10, numLen(a))+a;

            return to_string(a)[0] > to_string(b)[0];
        }
    };

public:
    string largestNumber(vector<int>& nums) {
        Compare compare;
        sort(nums.begin(), nums.end(), compare);
        string str = "";

        for(int i=0;i<nums.size();i+=1)
        if(str=="0" || str=="") str = to_string(nums[i]);
        else                    str += to_string(nums[i]);

        return str;
    }
};