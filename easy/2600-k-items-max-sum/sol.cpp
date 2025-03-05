#include <cmath>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ones = min(numOnes, k);
        k -= ones;
        k -= min(numZeros, k);
        int negs = min(numNegOnes, k);

        return ones - negs;
    }
};