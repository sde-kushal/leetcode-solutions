#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    long hoursSpent(vector<int> &piles, const int &rate) {
        long hrs = 0;
        for(int i=0;i<piles.size();i+=1)
            hrs += (piles[i]/rate) + (piles[i]%rate ? 1 : 0);
        return hrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = piles[0];
        for(int i=1;i<piles.size();i+=1)
            maxElement = max(maxElement,piles[i]);

        // do binary search over 1 to maxElement
        int left = 1, right = maxElement;
        int mid, found;

        while(left<=right) {
            mid = left + (right-left)/2;

            long spentHours = hoursSpent(piles, mid);
            if(spentHours > h) // increase our rate
                left = mid+1;
            else {
                found = mid;
                right = mid-1;      
            }
        }

        return found;
    }
};