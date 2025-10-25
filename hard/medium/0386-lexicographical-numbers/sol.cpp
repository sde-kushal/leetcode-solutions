#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicals(n,0);
        int curr = 1;

        for(int i=0; i<n; i+=1) {
            lexicals[i] = curr;
            if(curr*10 <= n)
                curr *= 10;
            else {
                while(curr%10==9 || curr>=n)
                    curr /= 10;
                curr += 1;
            }
        }

        return lexicals;
    }
};