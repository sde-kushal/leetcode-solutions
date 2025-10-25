using namespace std;

class Solution {
private:
    int checkAND(int low, int high) {
        for(;low<=high;low+=1)
            if(low%2==0)    return 0;
        return 1;
    }

public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) 
            return left;

        int i = 0, andSum = 0;
        while(right>0) {
            andSum += (1<<i) * checkAND(left,right);
            left >>= 1;
            right >>= 1;
            i += 1;
        }    

        return andSum;
    }
};