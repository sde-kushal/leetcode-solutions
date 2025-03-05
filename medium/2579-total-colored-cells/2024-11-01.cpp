using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long s = 0;
        for(int i=n-1;i>1;i-=1)
            s += i-1;
        
        return 1 + (s+n-1)*4;
    }
};