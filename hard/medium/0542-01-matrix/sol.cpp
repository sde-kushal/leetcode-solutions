#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans = mat;
        int m = mat.size(), n = mat[0].size();

        // top and left
        for(int i=0;i<m;i+=1)
            for(int j=0;j<n;j+=1) 
                if(ans[i][j]) {
                    int top  = i==0 ? INT_MAX-1 : min(INT_MAX-1, ans[i-1][j]);
                    int left = j==0 ? INT_MAX-1 : min(INT_MAX-1, ans[i][j-1]);
                    ans[i][j] = 1 + min(top, left);
                }

        // bottom and right
        for(int i=m-1;i>=0;i-=1)
            for(int j=n-1;j>=0;j-=1) 
                if(ans[i][j]) {
                    int bottom  = i==m-1 ? INT_MAX-1 : min(INT_MAX-1, ans[i+1][j]);
                    int right   = j==n-1 ? INT_MAX-1 : min(INT_MAX-1, ans[i][j+1]);
                    ans[i][j] = min(ans[i][j], 1 + min(bottom, right));
                }

        return ans;
    }
};