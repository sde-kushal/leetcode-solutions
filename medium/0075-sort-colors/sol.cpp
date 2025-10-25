#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1)    return;

        int low = 0, high = nums.size()-1, mid = 0;
        while(mid <= high) {
            if(nums[mid] < 1) {
                swap(nums[mid],nums[low]);
                low += 1;
                mid += 1;
            } 
            else if(nums[mid] > 1) {
                swap(nums[mid],nums[high]);
                high -= 1;
            }
            else 
                mid += 1;
        }   
    }
};