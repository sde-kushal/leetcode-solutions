#include <string>
using namespace std;

class Solution {
private:
    string getProduct(int r1, int r2, int i1, int i2) {
        int real = r1*r2 - i1*i2;
        int imaginary = r1*i2 + r2*i1;

        return to_string(real) + "+" + to_string(imaginary) + "i";
    }

    void getNumbers(string expr, int &real, int &img) {
        bool isReal = true;
        bool realNegative = false, imgNegative = false;
        real = 0, img = 0;

        for(int i=0;i<expr.size();i+=1) {
            if(expr[i]=='-')
                if(isReal)  realNegative= true;
                else        imgNegative = true;
            else if(expr[i]=='+')
                isReal = false;
            else if(expr[i]>='0' && expr[i]<='9') {
                if(isReal)  real = real*10 + static_cast<int>(expr[i]) - 48;
                else        img  = img*10 + static_cast<int>(expr[i]) - 48;
            }
        }

        if(realNegative)    real *= -1;
        if(imgNegative)     img *= -1;
    }

public:
    string complexNumberMultiply(string num1, string num2) {
        int r1, r2, i1, i2;
        getNumbers(num1,r1,i1);
        getNumbers(num2,r2,i2);
        return getProduct(r1,r2,i1,i2);
    }
};