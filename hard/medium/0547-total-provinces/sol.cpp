#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int presentCity = 0;
        int provinces = 0;

        queue<int> Q;

        while(presentCity != -1) {
            Q = queue<int>();

            Q.push(presentCity);
            while(!Q.empty()) {
                int curr = Q.front();
                visited[curr] = true;

                for(int i=0;i<isConnected.size();i+=1)
                    if(i!=curr && isConnected[curr][i] == 1 && !visited[i])
                        Q.push(i);
                
                Q.pop();
            }

            provinces += 1;
            presentCity = -1;

            for(int i=0;i<visited.size();i+=1)
                if(!visited[i]) {
                    presentCity = i;
                    break;
                }
        }

        return provinces;
    }
};