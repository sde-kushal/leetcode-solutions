#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int distinct = 0;
        unordered_map<int,int> colors, balls;
        vector<int> ans(queries.size(), 0);

        for(int i=0;i<queries.size();i+=1) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if(balls.count(ball) && colors.count(balls[ball])) {
                colors[balls[ball]] -= 1;
                if(colors[balls[ball]] == 0)
                    distinct -= 1;
            }
            
            balls[ball] = color;
            colors[color] += 1;
            if(colors[color] == 1)
                distinct += 1;

            ans[i] = distinct;
        }

        return ans;
    }
};