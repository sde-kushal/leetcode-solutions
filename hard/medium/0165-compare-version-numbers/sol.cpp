#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1 += '.';
        version2 += '.';

        long n1 = 0, n2 = 0;
        int i = 0, j = 0;

        while(i<version1.size() || j<version2.size()) {
            if(i>=version1.size())
                n1 = 0;
            else
                while(version1[i] != '.') {
                    n1 = n1 * 10 + static_cast<long>(version1[i]) - 48;
                    i += 1;
                }
            
            if(j>=version2.size())
                n2 = 0;
            else
                while(version2[j] != '.') {
                    n2 = n2 * 10 + static_cast<long>(version2[j]) - 48;
                    j += 1;
                }

            if(n1 < n2) return -1;
            if(n1 > n2) return 1;

            i += 1;
            j += 1;
            n1 = 0;
            n2 = 0;
        }

        return 0;
    }
};