#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    int getAllPossiblePairings(int n) {
        int allPairs = 0;
        for(int i=n-1;i>0;i--)
            allPairs += i;

        return allPairs;
    }

    int getHash(unordered_set<char> chars) {
        int hash = 0;
        for(auto it=chars.begin(); it!=chars.end(); it++)
            hash += (static_cast<int>(*it)-80)*(static_cast<int>(*it)-80);
        
        return hash;
    }

public:
    int similarPairs(vector<string>& words) {
        int max_similar_nodes = 0;
        int total_similar_nodes = 0;

        vector<bool>(26,false);
        unordered_map<int,int> similars;
        unordered_set<char> charSet;

        for(int i=0;i<words.size();i++) {
            charSet.clear();
            for(int j=0;j<words[i].size();j++)
                charSet.insert(words[i][j]);

            int bucketHash = getHash(charSet);
            if(similars.find(bucketHash)==similars.end())
                similars[bucketHash] = 1;
            else
                similars[bucketHash] += 1;
            
            if(similars[bucketHash] > max_similar_nodes) {
                max_similar_nodes = similars[bucketHash];
                total_similar_nodes = 1;
            }
            else if(similars[bucketHash] == max_similar_nodes) {
                total_similar_nodes += 1;
            }
        }

        if(max_similar_nodes <= 1)
            return 0;

        int pairs = getAllPossiblePairings(max_similar_nodes);
        return pairs*total_similar_nodes;
    }
};
