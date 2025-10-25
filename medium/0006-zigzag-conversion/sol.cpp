#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int getCols(int n, int len) {
        if(n==2)
            return floor(len/2) + len%2;
        
        int rem = len%(2*n-4);
        if(rem > 0)
            rem = rem <= n ? 1 : rem-n+1;

        return floor(len/(2*n-4))*(n-1) + rem;
    }

public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        int cols = getCols(numRows, s.size());

        vector<vector<char>> table(numRows,vector<char>(cols,' '));
        bool goZigZag = false;

        int currR = 0, currC = 0;

        for(int i=0;i<s.size();i+=1) {
            table[currR][currC] = s[i];
            if(!goZigZag) {
                if(currR==numRows-1) {
                    goZigZag = true;
                    currR -= 1;
                    currC += 1;
                }
                else currR += 1;
            }
            else {
                if(currR==0) {
                    goZigZag = false;
                    currR += 1;
                }
                else {
                    currR -= 1;
                    currC += 1;
                }
            }
        }

        string converted = "";

        for(int i=0;i<numRows;i+=1)
            for(int j=0;j<cols;j+=1)
                if(table[i][j]!=' ')
                    converted += table[i][j];

        return converted;
    }
};