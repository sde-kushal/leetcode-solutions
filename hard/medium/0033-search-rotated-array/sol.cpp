#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;

        while(low<=high) {
            if(nums[low]==target)   return low;
            if(nums[high]==target)   return high;
            
            mid = low + (high-low)/2;
            
            if(nums[mid]==target)   return mid;

            if(nums[mid] >= nums[low]) {
                if(target < nums[mid] && nums[low] < target)    
                        high = mid - 1;
                else    low = mid + 1;
            }
            else {
                if(target < nums[high] && nums[mid] < target)    
                        low = mid + 1;
                else    high = mid - 1;
            }
        }

        return -1;
    }
};