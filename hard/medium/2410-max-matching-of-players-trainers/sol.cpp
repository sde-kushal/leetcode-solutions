#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        
        int pairs = 0, trainer = 0;

        for(int i=0;i<players.size();i+=1) {
            while(trainer < trainers.size() && trainers[trainer] < players[i])
                trainer += 1;
            if(trainer == trainers.size())
                break;
            
            pairs += 1;
            trainer += 1;
        }

        return pairs;
    }
};