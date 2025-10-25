#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumN, sumM = 0;
        for(int i=0;i<rolls.size();i+=1)
            sumM += rolls[i];

        sumN = mean*(n+rolls.size()) - sumM;

        if(floor(sumN/n) > 6 || (floor(sumN/n)==6 && sumN%n>0) || sumN < n)
            return {};
        
        vector<int> otherHalf(n,floor(sumN/n));
        for(int i=0;i<sumN%n;i+=1)
            otherHalf[i] += 1;

        return otherHalf;
    }
};