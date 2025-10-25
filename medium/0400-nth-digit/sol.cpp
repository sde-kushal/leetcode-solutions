#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int num = 1, digits = 1;
        int offset = 0;

        while((long)(offset + 9 * digits * pow(10,digits-1)) < (long)n) {
            offset += 9 * digits * pow(10,digits-1);
            digits += 1;
            num *= 10;
        }

        n -= offset;
        num += (n-1)/digits;
        while(n > digits)
            n -= digits;

        return static_cast<int>(to_string(num)[n-1]) - 48;
    }
};