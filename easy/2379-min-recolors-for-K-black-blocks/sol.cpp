#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minRecolors = 0;
        int whites = 0;
        int left = 0, right = k-1;

        for(;left<=right;left+=1)
            if(blocks[left] == 'W') 
                whites += 1;
        
        minRecolors = whites;

        for(left=1,right+=1;right<blocks.size();right+=1,left+=1) {
            if(blocks[left-1]=='W') whites -= 1;
            if(blocks[right]=='W')  whites += 1;

            minRecolors = min(minRecolors, whites);
        }

        return minRecolors;
    }
};