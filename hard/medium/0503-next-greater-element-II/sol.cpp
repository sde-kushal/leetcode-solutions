#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i,j;
        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int j=0;j<2*nums.size();j+=1) {
            i = j % nums.size();
            if(st.empty() && j < nums.size()) 
                st.push(i);
            else {
                while(!st.empty() && nums[st.top()] < nums[i] && ans[st.top()]==-1) {
                    ans[st.top()] = nums[i];
                    st.pop();
                }
                if(j < nums.size())
                    st.push(i);
            }
        }

        return ans;
    }
};