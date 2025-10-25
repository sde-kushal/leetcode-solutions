#include <vector>
using namespace std;

// sieve of erastho...something
class Solution {
public:
    int countPrimes(int n) {
        if(n==0)
            return 0;

        int primes = 0;
        vector<bool> isPrime(n,true);
        isPrime[0] = false;

        for(int i=2;i<n;i+=1) {
          if(isPrime[i-1]) {
            primes += 1;
            for(int j=i*2;j<n;j+=i)
              isPrime[j-1] = false;
          }
        }

        return primes;
    }
};