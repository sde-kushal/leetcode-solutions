#include <vector>
#include <limits.h>
using namespace std;

class Solution {
private:
    int rounded(int x) { return x/2 + (x%2 ? 1 : 0); }

    int evaluate(int x, int k) { 
        int r = rounded(x);
        if(x >= k) 
            return min(r>=k ? r-k : INT_MAX, rounded(x-k)); 
        return r;
    }

public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        int operation1, operation2, no_operation, operation1_operation2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(op1+1, vector<int>(op2+1, 0)));

        for(int curr=n-1;curr>=0;curr-=1) 
            for(int i=0;i<=op1;i+=1)
                for(int j=0;j<=op2;j+=1) {
                    operation1 = i>0 ? rounded(nums[curr])+dp[curr+1][i-1][j] : INT_MAX;
                    operation2 = nums[curr]>=k && j>0 ? nums[curr]-k+dp[curr+1][i][j-1] : INT_MAX;
                    operation1_operation2 = i>0 && j>0 && nums[curr]>=k ? evaluate(nums[curr],k)+dp[curr+1][i-1][j-1] : INT_MAX;
                    no_operation = nums[curr]+dp[curr+1][i][j];

                    dp[curr][i][j] = min(operation1, min(operation2, min(operation1_operation2, no_operation)));
                }

        return dp[0][op1][op2];
    }
};