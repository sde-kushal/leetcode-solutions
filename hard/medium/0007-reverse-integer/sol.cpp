using namespace std;

class Solution {
public:
    int reverse(int x) {
        long rev = 0;

        while(x != 0) {
            if(x<0 && INT_MIN > rev*10 + x%10)         return 0;
            else if(x>=0 && INT_MAX < rev*10 + x%10)   return 0;

            rev = rev*10 + x%10;
            x /= 10;
        }

        return (int)(rev);
    }
};