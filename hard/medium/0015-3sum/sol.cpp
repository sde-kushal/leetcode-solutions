#include <vector>
using namespace std;

class Solution {
private:
    void exploreTriplets(vector<int> arr, int grapple, int left, int right, vector<vector<int>> &triplets) {
        if(arr[grapple] > 0 && arr[left] > 0 && arr[right] > 0)
            return;
        
        while(left < right) {
            int sum = arr[grapple] + arr[left] + arr[right];
            if(sum == 0) {
                triplets.push_back({ arr[grapple], arr[left], arr[right] });
                do { left += 1; }   while(left < arr.size() && arr[left-1]==arr[left]);
                do { right -= 1; }  while(right > grapple && arr[right+1]==arr[right]);
            }
            else if(sum > 0)
                right--;
            else 
                left++;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(),nums.end());

        int len = nums.size();
        int grapple = 0;
        for(; grapple < len-2; grapple++){
            exploreTriplets(nums,grapple,grapple+1,len-1,triplets);
            while(grapple+1 < len-2 && nums[grapple+1]==nums[grapple])
                grapple++;
        }
        
        return triplets;
    }
};