#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> intersections = {};
        int i = 0, j = 0;

        while(i < a.size() && j < b.size()) {
            if(a[i][1] < b[j][0])       i += 1;
            else if(a[i][0] > b[j][1])  j += 1;
            else {
                intersections.push_back({ max(a[i][0], b[j][0]), min(a[i][1], b[j][1]) });

                if(b[j][1] > a[i][1])       i += 1;
                else if(b[j][1] < a[i][1])  j += 1;
                else {
                    i += 1;
                    j += 1;
                }
            }
        }

        return intersections;
    }
};