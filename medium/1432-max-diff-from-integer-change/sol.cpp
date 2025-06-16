#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        int maxNum = 0, minNum = 0;
        int replaceDigitMax = -1, replaceDigitMin = -1;
        int minDigit = 0, maxDigit = 9;

        string str = to_string(num);

        for (int i = 0; i < str.size(); i += 1) {
            int digit = static_cast<int>(str[i]) - 48;

            // if not 9, lock this digit
            if (replaceDigitMax > -1 && digit == replaceDigitMax)
                maxNum = maxNum * 10 + maxDigit;
            else if (replaceDigitMax == -1 && str[i]!='9') {
                replaceDigitMax = digit;
                maxNum = maxNum * 10 + maxDigit;
                // cout << replaceDigitMax << endl;
            } 
            else maxNum = maxNum * 10 + digit;

            
            // if not 1 and 0, lock this digit
            if (replaceDigitMin > -1 && digit == replaceDigitMin)
                minNum = minNum * 10 + minDigit;
            else if (replaceDigitMin == -1 && str[i]!='0' && str[i]!='1') {
                replaceDigitMin = digit;
                minDigit = i > 0 ? 0 : 1;
                minNum = minNum * 10 + minDigit;
            } 
            else minNum = minNum * 10 + digit;
        }

        return maxNum - minNum;
    }
};