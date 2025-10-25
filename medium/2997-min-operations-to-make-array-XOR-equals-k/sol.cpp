#include <vector>
using namespace std;

class Solution {
private:
    int exploreBits(vector<int> bits, int k) {
        int arrBits = 0;
        
        // get odd or even 1s in array
        for(int i=0; i<bits.size(); i++)
            arrBits ^= bits[i]%2;

        if((k%2==0 && arrBits==1) || (k%2==1 && arrBits==0))
            return 1;
        return 0;
    }

public:
    int minOperations(vector<int>& nums, int k) {
        int maxNum = k;
        int flips = 0;

        for(int i=0;i<nums.size();i++)
            maxNum = max(maxNum, nums[i]);

        while(maxNum > 0) {
            flips += exploreBits(nums, k);
            k >>= 1;
            maxNum >>= 1;
            for(int i=0; i<nums.size();i++)
                nums[i] >>= 1;
        }

        return flips;
    }
};