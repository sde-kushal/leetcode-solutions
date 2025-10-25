#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        long long totalChemistry = 0;
        unordered_map<int,int> bag;

        for(int i=0;i<skill.size();i+=1){
            sum += skill[i];
            if(bag.find(skill[i])!=bag.end())   bag[skill[i]] += 1;
            else                                bag[skill[i]] = 1;
        }
            
        int target = (2*sum)/skill.size();
        
        for(int i=0;i<skill.size();i+=1) {
            if(bag[skill[i]] == 0)
                continue;
                
            if(bag.find(target - skill[i])!=bag.end() && bag[target - skill[i]] > 0) {
                totalChemistry += skill[i] * (target - skill[i]);
                bag[skill[i]] = max(0,bag[skill[i]]-1);
                bag[target-skill[i]] = max(0,bag[target-skill[i]]-1);
            }
            else 
                return -1;
        }

        return totalChemistry;
    }
};