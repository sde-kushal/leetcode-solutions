#include <string>
using namespace std;

class Solution {
private:
    bool isNotAlphaNumeric(char ch) {
        return !(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') && !(ch >= '0' && ch <= '9');
    }

    bool notEqual(char a, char b) {
        return tolower(a) != tolower(b);
    }

public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left <= right) {
            while(left <= right && isNotAlphaNumeric(s[left]))
                left += 1;
            while(right >= left && isNotAlphaNumeric(s[right]))
                right -= 1;

            if(left > right)
                return true;
            if(notEqual(s[left], s[right]))
                return false;
            
            left += 1;
            right -= 1;
        }

        return true;
    }
};