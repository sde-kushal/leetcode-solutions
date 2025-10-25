#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==right)
            return { -1, -1 };
        
        vector<int> isPrime(right+1,true);
        isPrime[0] = false;
        isPrime[1] = false;

        int minDiff = INT_MAX, lastPrime = 0;
        vector<int> ans(2,-1);

        for(int i=2;i<=right;i+=1) {
            if(isPrime[i]) {
                for(int j=i*2;j<=right;j+=i)
                    isPrime[j] = false;
                if(i>=left) {
                    if(lastPrime > 0 && minDiff > i-lastPrime) {
                        minDiff = i-lastPrime;
                        ans = { lastPrime, i };
                    }
                    lastPrime = i;
                }
            }
        }

        return ans;
    }
};