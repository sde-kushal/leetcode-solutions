#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> matrix(rowSum.size(), vector<int>(colSum.size(), 0));
        int tempMin;

        for(int i=0;i<rowSum.size();i+=1)
            for(int j=0;j<colSum.size();j+=1) {
                if(rowSum[i]==0 || colSum[j]==0)
                    continue;

                tempMin = min(rowSum[i],colSum[j]);
                matrix[i][j] = tempMin;
                rowSum[i] -= tempMin;
                colSum[j] -= tempMin;
            }
        
        return matrix;
    }
};