#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string rle = "1", temp;
        int low, high;
        
        for(;n>1;n-=1) {
            temp = "";
            low = 0, high = 0;
            while(high < rle.size()) {
                while(high < rle.size() && rle[high]==rle[low])  
                    high += 1;
                temp += to_string(high-low) + rle[low];
                low = high;
            }
            rle = temp;
        }

        return rle;
    }
};