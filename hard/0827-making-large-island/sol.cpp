#include <vector>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <utility>
#include <limits.h>
using namespace std;

#define VISITED -1
#define ALIAS INT_MAX

class Solution {
private:
    int performBFS(vector<vector<int>>& grid, int r, int c, unordered_set<int>& boundaries) {
        queue<int> Q;
        int area = 0;

        Q.push(encodeCoords(r,c));
        grid[r][c] = VISITED;

        while(!Q.empty()) {
            pair<int,int> coords = decodeCoords(Q.front());
            area += 1;
            Q.pop();
            
            if(coords.first-1>=0) {
                if(grid[coords.first-1][coords.second] == 1) {
                    grid[coords.first-1][coords.second] = VISITED;
                    Q.push(encodeCoords(coords.first-1, coords.second));
                }
                else if(grid[coords.first-1][coords.second] != VISITED)
                    boundaries.insert(encodeCoords(coords.first-1, coords.second));
            }
            if(coords.first+1<grid.size()) {
                if(grid[coords.first+1][coords.second] == 1) {
                    grid[coords.first+1][coords.second] = VISITED;
                    Q.push(encodeCoords(coords.first+1, coords.second));
                }
                else if(grid[coords.first+1][coords.second] != VISITED)
                    boundaries.insert(encodeCoords(coords.first+1, coords.second));
            }
            if(coords.second-1>=0) {
                if(grid[coords.first][coords.second-1] == 1) {
                    grid[coords.first][coords.second-1] = VISITED;
                    Q.push(encodeCoords(coords.first, coords.second-1));
                }
                else if(grid[coords.first][coords.second-1] != VISITED)
                    boundaries.insert(encodeCoords(coords.first, coords.second-1));
            }
            if(coords.second+1<grid[0].size()) {
                if(grid[coords.first][coords.second+1] == 1) {
                    grid[coords.first][coords.second+1] = VISITED;
                    Q.push(encodeCoords(coords.first, coords.second+1));
                }
                else if(grid[coords.first][coords.second+1] != VISITED)
                    boundaries.insert(encodeCoords(coords.first, coords.second+1));
            }
        }

        return area;
    }

    void fillBoundaries(vector<vector<int>>& grid, unordered_set<int>& boundaries, int &currSize, int &maxSize) {
        for(auto it=boundaries.begin();it!=boundaries.end();it++) {
            pair<int,int> coords = decodeCoords(*it);
            grid[coords.first][coords.second] = (grid[coords.first][coords.second] == ALIAS ? 1 : grid[coords.first][coords.second]) + currSize;
            maxSize = max(maxSize, grid[coords.first][coords.second] + 1);
            if(grid[coords.first][coords.second] == 1)
                grid[coords.first][coords.second] = ALIAS;
        }
    }

    pair<int,int> decodeCoords(int x) {
        return { x/1000 - 500, x%1000 - 500 };
    }

    int encodeCoords(int r, int c) {
        return (r+500)*1000 + (c+500);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int maxSize = 0, currSize = 0;
        unordered_set<int> boundaries;

        for(int i=0;i<grid.size();i+=1)
            for(int j=0;j<grid[0].size();j+=1) {
                if(grid[i][j]==1) {
                    currSize = performBFS(grid,i,j,boundaries);
                    maxSize = max(maxSize,currSize);
                    fillBoundaries(grid,boundaries,currSize,maxSize);
                    boundaries.clear();
                }
            }

        return maxSize > 0 ? maxSize : 1;
    }
};