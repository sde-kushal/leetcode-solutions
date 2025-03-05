#include <vector>
using namespace std;

class Solution {
private:
    void fillRemaining(vector<vector<int>>& merged, vector<vector<int>>& arr, int i) {
        for(;i<arr.size();i+=1)
            merged.push_back(arr[i]);
    }

public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> merged;
        int p1 = 0, p2 = 0;

        while(p1<nums1.size() && p2<nums2.size()) {
            // check ids same
            if(nums1[p1][0] == nums2[p2][0]) {
                merged.push_back({ nums1[p1][0], nums1[p1][1] + nums2[p2][1] });
                p1 += 1;
                p2 += 1;
            }

            // when ids not same
            else if(nums1[p1][0] < nums2[p2][0]) {
                merged.push_back(nums1[p1]);
                p1 += 1;
            }

            else {
                merged.push_back(nums2[p2]);
                p2 += 1;
            }
        }

        // append remaining
        if(p1<nums1.size())         fillRemaining(merged,nums1,p1);
        else if(p2<nums2.size())    fillRemaining(merged,nums2,p2);

        return merged;
    }
};