#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mid;

        while(low<=high) {
            mid = low + (high-low)/2;

            if(nums[mid] > nums[high])  
                low = mid+1;
            else {
                if(mid == 0 || nums[mid] < nums[mid-1])
                    break;
                high = mid;
            }
        }

        return nums[mid];
    }
};