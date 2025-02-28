#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
    int setBits(int x) {
        int ones = 0;
        while(x > 0) {
            if(x%2==1)  ones += 1;
            x >>= 1;
        }
        return ones;
    }

    int generateDecimal(vector<int>& bit) {
        int dec = 0, p = 1;
        for(int i=0;i<bit.size();i+=1) {
            dec += bit[i] * p;
            p <<= 1;
        }
        return dec;
    }

public:
    int minimizeXor(int num1, int num2) {
        int bits1 = setBits(num1);
        int bits2 = setBits(num2);

        if(bits1 == bits2)
            return num1;

        int rem;
        vector<int> bit;
        
        if(bits2 < bits1) { // ===========================
            rem = bits1 - bits2;

            while(num1 > 0) {
                if(num1%2==0) 
                    bit.push_back(0);
                else {
                    if(rem > 0) {
                        bit.push_back(0);
                        rem -= 1;
                    } 
                    else bit.push_back(1);
                }
                num1 >>= 1;
            }

            return generateDecimal(bit);
        }

        // bits2 > bits1 ==========================================
        rem = bits2 - bits1;

        while(rem > 0 || num1 > 0) {
            if(num1 == 0) {
                bit.push_back(1);
                rem -= 1;
                continue;
            }

            if(num1%2==0) {
                if(rem > 0) {
                    bit.push_back(1);
                    rem -= 1;
                }
                else bit.push_back(0);
            }
            else bit.push_back(1);

            num1 >>= 1;
        }

        return generateDecimal(bit);
    }
};