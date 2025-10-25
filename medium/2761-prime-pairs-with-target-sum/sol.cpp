#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findPrimePairs(int n) {
      if(n<=1)    
        return {};
        
      // use sieve of erasto-- to pre-compute [1,n]
      vector<bool> isPrime(n, true);
      isPrime[0] = isPrime[1] = false; // for readability of index i == actual number
        
      for(int i=2;i<n;i+=1) {
        if(isPrime[i]) {
          for(int j=i*2;j<n;j+=i)
            isPrime[j] = false;
        }
      }
        
      // if isPrime[i] && isPrime[n-i] then add to list of answers
      vector<vector<int>> primePairs;
      for(int i=2;i<=n/2;i+=1)
        if(isPrime[i] && isPrime[n-i])
          primePairs.push_back({ i, n-i });
                
      return primePairs;
  }
};