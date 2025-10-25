#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    void rotAdjacents(vector<vector<int>> &grid, int r, int c, queue<pair<int,int>> &Q, int &count, int &total) {
        if(r-1 >= 0 && grid[r-1][c]==1) {
            grid[r-1][c] = 2;
            count += 1;
            Q.push({r-1,c});
            total -= 1;
        }     
        if(r+1 < grid.size() && grid[r+1][c]==1) {
            grid[r+1][c] = 2;
            count += 1;
            Q.push({r+1,c});
            total -= 1;
        }   
        if(c-1 >= 0 && grid[r][c-1]==1) {
            grid[r][c-1] = 2;
            count += 1;
            Q.push({r,c-1});
            total -= 1;
        }     
        if(c+1 < grid[0].size() && grid[r][c+1]==1) {
            grid[r][c+1] = 2;
            count += 1;
            Q.push({r,c+1});
            total -= 1;
        }   
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        int oranges = 0;
        int count = 0, nextCount = 0;
        int mins = 0;

        for(int i=0;i<grid.size();i+=1)
            for(int j=0;j<grid[0].size();j+=1) {
                if(grid[i][j] == 1)
                    oranges += 1;
                if(grid[i][j] == 2) {
                    Q.push({i,j});
                    count += 1;
                }
            }

        
        // perform bfs
        while(!Q.empty()) {
            if(count == 0) {
                count = nextCount;
                nextCount = 0;
                mins += 1;
            }
            else {
                int i = Q.front().first, j = Q.front().second;
                Q.pop();
                count -= 1;
                rotAdjacents(grid,i,j,Q,nextCount,oranges);
            }
        }

        return oranges > 0 ? -1 : mins;

    }
};