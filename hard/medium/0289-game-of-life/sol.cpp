#include <vector>
using namespace std;

/*
==========================
                NOW
              0     1
==========================
         0 || 2     3
PRESENT -> ||
         1 || 4     5
*/

class Solution {
private:
    int fate(vector<vector<int>>& board, int &i, int &j) {
        int sum = 0;
        
        if(j-1>=0) sum += decodePresent(board[i][j-1]);
        if(j+1<board[0].size()) sum += decodePresent(board[i][j+1]);
        
        if(i-1>=0) {
            sum += decodePresent(board[i-1][j]);
            if(j-1>=0) sum += decodePresent(board[i-1][j-1]);
            if(j+1<board[0].size()) sum += decodePresent(board[i-1][j+1]);
        }
        
        if(i+1<board.size()) {
            sum += decodePresent(board[i+1][j]);
            if(j-1>=0) sum += decodePresent(board[i+1][j-1]);
            if(j+1<board[0].size()) sum += decodePresent(board[i+1][j+1]);
        }

        return board[i][j] ? (sum == 2 || sum == 3 ? 1 : 0) : (sum == 3 ? 1 : 0);
    }

    int decodePresent(int &num) { return num <= 1 ? num : (num == 2 || num == 3 ? 0 : 1); }
    int decodeNext(int &num)    { return num <= 1 ? num : (num == 2 || num == 4 ? 0 : 1); }
    
    int encode(int present, int next) { 
        if(present) return next ? 5 : 4;
        return next ? 3 : 2; 
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i+=1)
            for(int j=0;j<board[0].size();j+=1) 
                board[i][j] = encode(board[i][j], fate(board,i,j));

        for(int i=0;i<board.size();i+=1)
            for(int j=0;j<board[0].size();j+=1) 
                board[i][j] = decodeNext(board[i][j]);
    }
};