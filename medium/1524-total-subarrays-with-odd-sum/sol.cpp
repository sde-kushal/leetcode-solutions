#include <vector>
using namespace std;

#define MOD 1000'000'007

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    int total = 0, s = 0, n = arr.size();
    vector<vector<int>> pre(2,vector<int>(n,0));
    bool isOne;

    for(int i=0;i<n;i+=1)
      pre[0][i] = ((i==0 ? 0 : pre[0][i-1]) + arr[i]) % 2;

    for(int i=n-1;i>=0;i-=1) {
      isOne = pre[0][i] == 1;
      pre[0][i] = (i==n-1 ? 0 : pre[0][i+1]) + (isOne ? 1 : 0);
      pre[1][i] = (i==n-1 ? 0 : pre[1][i+1]) + (!isOne ? 1 : 0);
    }

    for(int i=0;i<n;i+=1) {
      total = (total + pre[s][i]) % MOD;
      s ^= arr[i] % 2;
    }

    return total;
  }
};