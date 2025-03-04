using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(;n>0;n/=3) 
            if(n%3 == 2)
                return false;

        return true;
    }
};