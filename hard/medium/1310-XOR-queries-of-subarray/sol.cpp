#include <vector>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size()), 
                    prefix(arr.size());
        int currXOR = 0;
        for(int i=0;i<arr.size();i++) {
            currXOR ^= arr[i];
            prefix[i] = currXOR;
        }

        int former, latter;

        for(int i=0;i<queries.size();i++) {
            currXOR = 0;
            former = queries[i][1];
            latter = queries[i][0];

            if(former == latter)
                currXOR = arr[former];
            else if(latter == 0)
                currXOR = prefix[former];  
            else
                currXOR = prefix[former] ^ prefix[latter-1];

            ans[i] = currXOR;
        }

        return ans;
    }
};