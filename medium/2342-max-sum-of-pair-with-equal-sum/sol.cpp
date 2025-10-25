#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

class Solution {
private:
    int getDigitSums(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int maxSum = 0;
        unordered_map<int,pair<int,int>> sumHighests;
        unordered_map<int,int> digitSums;

        for(int i=0;i<nums.size();i+=1) {
            int digitSum = 0;

            // find hashmap has digit sum
            if(digitSums.count(nums[i])) 
                digitSum = digitSums[nums[i]];
            else 
                digitSum = getDigitSums(nums[i]);

            
            // check sumHighests for that key will modify
            if(sumHighests.count(digitSum)) {
                pair<int,int> temp = sumHighests[digitSum];
                if(temp.first < nums[i]) {
                    if(temp.second < nums[i]) {
                        sumHighests[digitSum].first = temp.second;
                        sumHighests[digitSum].second = nums[i];
                    }
                    else {
                        sumHighests[digitSum].first = nums[i];
                    }

                    // modify and update maxSum
                    maxSum = max(maxSum, sumHighests[digitSum].first + sumHighests[digitSum].second);
                }
            }
            else   sumHighests[digitSum] = { 0, nums[i] };
        }


        return maxSum > 0 ? maxSum : -1; 
    }
};