#include <vector>
using namespace std;

class Solution {
private:
    void exploreTriplets(vector<int> arr, int &grapple, int &left, int &right, int &closest, int target, bool &hard_break) {

        while(left < right) {
            int sum = arr[grapple] + arr[left] + arr[right];
            if(sum==target || abs(target-sum) < abs(target-closest)) {
                closest = sum;
                if(sum==target) {
                    hard_break = true;
                    return;
                }
            }
            if(sum < target)
                do { left++; } while(left < arr.size() && arr[left]==arr[left-1]);
            else if(sum > target)
                do { right--; } while(right > grapple && arr[right]==arr[right+1]);
        }
    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        bool hard_reset = false;
        int closest = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        int grapple=0, left = 1, right = len-1;
        
        for(; grapple < len-2; grapple++) {
            left = grapple + 1;
            right = len-1;
            exploreTriplets(nums,grapple,left,right,closest,target,hard_reset);
            if(hard_reset)
                return closest;
            
            if(grapple+1 < len-2 && nums[grapple]==nums[grapple+1])
                grapple++;
        }

        return closest;
    }
};