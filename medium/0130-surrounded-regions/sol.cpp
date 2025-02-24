#include <stack>
#include <vector>
#include <utility>
using namespace std;

class Solution {
    private:
        void dfs(vector<vector<char>>& board, vector<vector<bool>>& aux, int row, int col, const int &m, const int &n) {
            stack<pair<int,int>> st;
            st.push({row,col});
    
            while(!st.empty()) {
                pair<int,int> coord = st.top();
                st.pop();
    
                aux[coord.first][coord.second] = true;
    
                // top
                if(coord.first-1>=0 && board[coord.first-1][coord.second]=='O' && !aux[coord.first-1][coord.second])
                    st.push({coord.first-1,coord.second});
                // bottom
                if(coord.first+1<m && board[coord.first+1][coord.second]=='O' && !aux[coord.first+1][coord.second])
                    st.push({coord.first+1,coord.second});
                // left
                if(coord.second-1>=0 && board[coord.first][coord.second-1]=='O' && !aux[coord.first][coord.second-1])
                    st.push({coord.first,coord.second-1});
                // right
                if(coord.second+1<n && board[coord.first][coord.second+1]=='O' && !aux[coord.first][coord.second+1])
                    st.push({coord.first,coord.second+1});
            }
        }
    
    public:
        void solve(vector<vector<char>>& board) {
            const int ROWS = board.size(), COLS = board[0].size();
    
            if(ROWS<=2 || COLS<=2)
                return;
    
            vector<vector<bool>> uncapturable(ROWS, vector<bool>(COLS, false));
            
            // traverse boundaries
            for(int i=0;i<ROWS;i+=1) {
                // perform DFS when cell == "O" and switch unc[i][j] = true
                if(board[i][0]=='O' && !uncapturable[i][0]) 
                    dfs(board,uncapturable,i,0,ROWS,COLS);
                if(board[i][COLS-1]=='O' && !uncapturable[i][COLS-1]) 
                    dfs(board,uncapturable,i,COLS-1,ROWS,COLS);
            }
        
            for(int i=0;i<COLS;i+=1) {
                if(board[0][i]=='O' && !uncapturable[0][i]) 
                    dfs(board,uncapturable,0,i,ROWS,COLS);
                if(board[ROWS-1][i]=='O' && !uncapturable[ROWS-1][i]) 
                    dfs(board,uncapturable,ROWS-1,i,ROWS,COLS);
            }
    
    
            // iterate over matrix and capture "O" -> "X" if unc[i][j] == true
            for(int i=1;i<ROWS-1;i+=1)
                for(int j=1;j<COLS-1;j+=1)
                    if(board[i][j] == 'O' && !uncapturable[i][j])
                        board[i][j] = 'X';
        }
    };