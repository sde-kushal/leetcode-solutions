#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int getDigits(int n) {
        n = abs(n);
        int digits = 0;

        while(n>0) {
            n /= 10;
            digits += 1;
        }

        return digits;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> availablePrefixes;
        int lcp = 0;

        for(int i=0;i<arr1.size();i+=1)
            while(arr1[i]>0 && availablePrefixes.count(arr1[i])==0) {
                availablePrefixes.insert(arr1[i]);
                arr1[i] /= 10;
            }
        
        for(int i=0;i<arr2.size();i+=1) {
            while(arr2[i] > 0 && availablePrefixes.count(arr2[i])==0)
                arr2[i] /= 10;
            if(arr2[i] > 0)
                lcp = max(lcp, getDigits(arr2[i]));
        }

        return lcp;
    }
};