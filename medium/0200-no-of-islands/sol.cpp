#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
  private:
    void bfs(vector<vector<char>>& grid, const int &m, const int &n, int &row, int &col, vector<vector<bool>> &aux) {
        queue<pair<int,int>> visited;
        
        visited.push({row,col});
        aux[row][col] = true;

        while(!visited.empty()) { 
          pair<int,int> coord = visited.front();
          visited.pop();

          if(coord.first-1>=0 && grid[coord.first-1][coord.second]=='1' && !aux[coord.first-1][coord.second]) {
            visited.push({coord.first-1,coord.second});
            aux[coord.first-1][coord.second] = true;
          }

          if(coord.first+1<m && grid[coord.first+1][coord.second]=='1' && !aux[coord.first+1][coord.second]) {
            visited.push({coord.first+1,coord.second});
            aux[coord.first+1][coord.second] = true;
          }

          if(coord.second-1>=0 && grid[coord.first][coord.second-1]=='1' && !aux[coord.first][coord.second-1]) {
            visited.push({coord.first,coord.second-1});
            aux[coord.first][coord.second-1] = true;
          }

          if(coord.second+1<n && grid[coord.first][coord.second+1]=='1' && !aux[coord.first][coord.second+1]) {
            visited.push({coord.first,coord.second+1});
            aux[coord.first][coord.second+1] = true;
          }
        }
    }

  public:
    int numIslands(vector<vector<char>>& grid) {
      int islands = 0;
      const int ROWS = grid.size(), COLS = grid[0].size();
      vector<vector<bool>> visited(ROWS, vector<bool>(COLS,false));

      // traverse grid
      for(int i=0;i<ROWS;i+=1)
        for(int j=0;j<COLS;j+=1) {
          if(grid[i][j]=='1' && !visited[i][j]) {
            islands += 1;

            // use bfs to traverse island
            bfs(grid,ROWS,COLS,i,j,visited);
          }
        }
      
      return islands;
    }
  };