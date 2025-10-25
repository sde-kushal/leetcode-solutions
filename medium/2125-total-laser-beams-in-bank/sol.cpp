#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0;
        int prevFloor = 0, floorBeams = 0;

        for(int i=0;i<bank.size();i+=1) {
            floorBeams = 0;
            for(int j=0;j<bank[i].size();j+=1)
                floorBeams += static_cast<int>(bank[i][j]) - 48;
            
            if(floorBeams > 0) {
                beams += prevFloor*floorBeams;
                prevFloor = floorBeams;
            }
        }

        return beams;
    }
};