#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1000'000'007;
    int total = 0, s = 0, n = arr.size();
    vector<vector<int>> pre(3,vector<int>(n,0));

    for(int i=0;i<n;i+=1)
      pre[0][i] = ((i==0 ? 0 : pre[0][i-1]) + arr[i]) % 2;

    for(int i=n-1;i>=0;i-=1) {
      pre[1][i] = (i==n-1 ? 0 : pre[1][i+1]) + (pre[0][i]==1 ? 1 : 0);
      pre[2][i] = (i==n-1 ? 0 : pre[2][i+1]) + (pre[0][i]==0 ? 1 : 0);
    }

    for(int i=0;i<n;i+=1) {
      total = (total + pre[s+1][i]) % MOD;
      s ^= arr[i] % 2;
    }

    return total;
  }
};