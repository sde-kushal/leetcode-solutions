#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,vector<int>> store;
        string tempR, tempC;
        int pairs = 0;

        for(int i=0;i<grid.size();i+=1) {
            tempR = "";
            tempC = "";
            for(int j=0;j<grid.size();j+=1) {
                tempR += to_string(grid[i][j]) + ",";
                tempC += to_string(grid[j][i]) + ",";
            }
            
            if(store.find(tempR)!=store.end()) {
                store[tempR][0] += 1;
                pairs += store[tempR][1];
            }
            else    store[tempR] = { 1, 0 };
            
            if(store.find(tempC)!=store.end()) {
                store[tempC][1] += 1;
                pairs += store[tempC][0];
            }
            else    store[tempC] = { 0, 1 };
        }
        
        return pairs;
    }
};