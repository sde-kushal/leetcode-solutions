class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i+=1)
            if(nums[i]%3) ans += 1;
        
        return ans;
    }
};