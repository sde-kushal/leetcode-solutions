#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int digit(char ch) { return static_cast<int>(ch)-48; }

public:
    int maximumSwap(int num) {
        if(num < 10)
            return num;

        vector<int> lastFound(10,-1);
        string str = to_string(num);
        for(int i=0;i<str.size();i+=1)
            lastFound[digit(str[i])] = i;
        
        int maxDigit = 9;
        while(lastFound[maxDigit] == -1)
            maxDigit -= 1;
        
        for(int i=0;i<str.size();i+=1) {
            if(digit(str[i]) < maxDigit) {
                char temp = str[i];
                str[i] = str[lastFound[maxDigit]]; 
                str[lastFound[maxDigit]] = temp;
                break;
            }

            if(digit(str[i]) == maxDigit && i == lastFound[maxDigit]) {
                lastFound[maxDigit] = -1;
                while(maxDigit >= 0 && lastFound[maxDigit] == -1)
                    maxDigit -= 1;
            }
        }
        
        return stoi(str);
    }
};