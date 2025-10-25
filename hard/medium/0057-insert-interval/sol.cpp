#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> n;
        int l = -1, r = -1;
        bool inserted = false;

        // check new interval comes beforehand
        if(intervals.size() == 0 || newInterval[1] < intervals[0][0]) {
            n.push_back(newInterval);
            inserted = true;

            for(int i=0;i<intervals.size();i+=1)
                n.push_back(intervals[i]);
        }
        else {
            for (int i = 0; i < intervals.size(); i += 1) {
                // out of range
                if (intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1]) {
                    if(i > 0 && !inserted && intervals[i][0] > newInterval[1] && intervals[i-1][1] < newInterval[0]) {
                        n.push_back(newInterval);
                        l = r = -1;
                        inserted = true;
                    }
                    else if (l >= 0 && r >= 0 && !inserted) {
                        n.push_back({l, r});
                        l = r = -1;
                        inserted = true;
                    }

                    n.push_back(intervals[i]);
                    continue;
                }

                // within range
                if (l < 0)
                    l = intervals[i][0] < newInterval[0] ? intervals[i][0] : newInterval[0];

                r = max(newInterval[1], intervals[i][1]);
            }

            if (!inserted)
                if (l == -1 && r == -1) n.push_back(newInterval);
                else                    n.push_back({l, r});
        }

        return n;
    }
};