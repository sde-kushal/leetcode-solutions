#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) 
            return intervals;

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;
        int low = 0, high = 0;

        for(int ptr=1;ptr<intervals.size();ptr+=1) {
            if(intervals[ptr][0] <= intervals[high][1] && intervals[ptr][1] > intervals[high][1])
                high = ptr;
            else if(intervals[ptr][0] > intervals[high][1]) {
                merged.push_back({ intervals[low][0], intervals[high][1] });
                low = ptr;
                high = ptr;
            }
        }

        merged.push_back({ intervals[low][0], intervals[high][1] });
        return merged;
    }
};