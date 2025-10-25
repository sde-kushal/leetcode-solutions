#include <vector>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long completeDays = 0;
        vector<int> buckets(24,0);

        for(int i=0;i<hours.size();i+=1) {
            completeDays += buckets[hours[i] % 24];
            buckets[(24 - hours[i] % 24) % 24] += 1;
        }

        return completeDays;
    }
};