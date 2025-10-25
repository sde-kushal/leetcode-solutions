using namespace std;

class Solution {
private:
    int compareBits(int a, int b, int c) {
        if(c%2==0) {
            if(a%2==1 && b%2==1)        return 2;
            else if(a%2==1 || b%2==1)   return 1;
        }
        if(c%2==1) {
            if(a%2==0 && b%2==0)        return 1;
        }
        return 0;
    }

public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        int maxNum = max(a,max(b,c));
        
        while(maxNum>0) {
            flips += compareBits(a,b,c);
            a >>= 1;
            b >>= 1;
            c >>= 1;
            maxNum >>= 1;
        }

        return flips;
    }
};