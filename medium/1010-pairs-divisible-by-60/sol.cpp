#include <vector>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int pairs = 0;
        vector<int> counts(60,0);

        for(int i=0;i<time.size();i+=1) {
            pairs += counts[time[i] % 60];
            counts[(60 - time[i] % 60) % 60] += 1;
        }

        return pairs;
    }
};