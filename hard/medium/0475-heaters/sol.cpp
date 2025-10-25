#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int standard = -1, closest = 0;
        for(int i=0;i<houses.size();i+=1) {
            while(closest+1 < heaters.size() && heaters[closest] < houses[i])
                closest += 1;

            if(closest==heaters.size()-1 && heaters[closest] < houses[i])
                standard = max(standard, houses[i] - heaters[closest]);
            else if(closest==0)  
                standard = max(standard, heaters[0] - houses[i]);
            else            
                standard = max(standard, min(houses[i] - heaters[closest-1], heaters[closest] - houses[i]));
        }

        return standard;
    }
};