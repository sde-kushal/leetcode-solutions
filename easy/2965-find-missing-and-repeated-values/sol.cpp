#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = (n*n)*(n*n+1)/2;
        int dup = 0;
        vector<bool> exists(n*n,false);

        for(int i=0;i<n;i+=1)
            for(int j=0;j<n;j+=1) {
                if(!dup && exists[grid[i][j]-1])  
                    dup = grid[i][j];
                else    exists[grid[i][j]-1] = true;
                sum -= grid[i][j];
            }

        sum += dup;

        return { dup, sum };
    }
};