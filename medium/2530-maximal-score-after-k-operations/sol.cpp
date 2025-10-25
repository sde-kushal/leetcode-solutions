#include <vector>
#include <queue>
using namespace std;

class Solution {
public : 
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> heap;
        for (int i = 0; i < nums.size(); i += 1)
            heap.push(nums[i]);

        int curr = 0;

        for (int i = 0; i < k; i += 1) {
            if (!heap.empty() && curr <= heap.top()) {
                heap.push(curr);
                curr = heap.top();
                heap.pop();
            }
            score += curr;
            curr = ceil((double)curr/3.0);
        }

        return score;
    }
};