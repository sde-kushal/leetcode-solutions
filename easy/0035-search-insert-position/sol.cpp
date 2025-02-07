#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;

        while(low<=high) {
            mid = low + (high-low)/2;

            if(nums[mid]==target)    return mid;
            else if(mid-1 >=0 && nums[mid-1]<target && nums[mid]>target)  return mid;
            else if(mid+1 <nums.size() && nums[mid+1]>target && nums[mid]<target)  return mid+1;

            if(nums[mid] < target)  low += 1;
            else                    high -= 1;
        }

        return target < nums[0] ? 0 : nums.size();
    }
};