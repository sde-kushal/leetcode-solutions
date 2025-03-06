using namespace std;

class Solution {
public:
    int numSquares(int n) {
      int maxCoin = floor(sqrt(n)), val;
      vector<int> dp(n,n);

      for(int i=0;i<n;i+=1) 
        for(int j=1;j<=maxCoin;j+=1) {
          val = j*j;
          if(val > i+1)   continue;
          if(val == i+1)  dp[i] = 1;
          else            dp[i] = min(dp[i],1+dp[i-val]);
        }

      return dp[n-1];
    }
};
