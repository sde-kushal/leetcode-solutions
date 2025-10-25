using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int uniques = 1;
        for(int i=1;i<=n;i+=1) {
            int sum = 9;
            for(int j=9;j>=9-(i-2);j-=1)
                sum *= j;
            uniques += sum;
        }

        return uniques;
    }
};