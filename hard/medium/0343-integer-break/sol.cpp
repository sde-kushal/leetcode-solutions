using namespace std;

/*
for a number n being divided into x parts, then product is x^(n/x)
derivative of it = (n/x) * x^(n/x - 1) + n*logx
log x to be max => 2 < e < 3
so max 2 or 3 should be selected 

*/

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;

        int prod = 1;
        while(n>0) {
            if(n==2 || n==3 || n==4) {
                prod *= n;
                break;
            }

            prod *= 3;
            n -= 3;
        }

        return prod;
    }
};