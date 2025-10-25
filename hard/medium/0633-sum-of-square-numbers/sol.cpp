#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0, high = ceil(sqrt(c));
        long sum = 0;

        while(low <= high) {
            sum = low*low + high*high;
            if(sum == c)   
                return true;
            if(sum < c) left += 1;
            else        high -= 1;
        }

        return false;
    }
};