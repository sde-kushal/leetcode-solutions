#include <vector>
using namespace std;

class Solution {
private:
    bool consumeChalk(int &currStudent, int totalStudents, int chalks, int &k) {
        if(chalks > k) 
            return false;
        
        k -= chalks;
        currStudent = (currStudent + 1) % totalStudents;
        return true;
    }

public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int curr = 0, n = chalk.size();
        if(n == 1) return n - 1;

        int beforeStart = k;
        for(auto itr: chalk) {
            if(!consumeChalk(curr,n,chalk[curr],k))
                return curr;
        }

        int fullCycleChalks = beforeStart - k;
        int skips = floor(k / fullCycleChalks);
        k = k % fullCycleChalks;

        while(consumeChalk(curr,n,chalk[curr],k));
        return curr;     
    }
};