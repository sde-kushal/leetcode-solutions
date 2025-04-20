#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> counts;
        int rabbits = 0;

        for(int i=0;i<answers.size();i+=1) {
            int ans = answers[i];

            // if in counts, decrease and move with next one
            if(counts.find(ans)!=counts.end() && counts[ans] > 0) {
                counts[ans] -= 1;
            }

            // if not accounted, increase rabbits by 1 + num[i]
            else {
                counts[ans] = ans;
                rabbits += 1 + ans;
            }
        }

        return rabbits;
    }
};