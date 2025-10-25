#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextWarmDays = vector<int>(temperatures.size(), 0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i+=1) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                nextWarmDays[st.top()] = i - st.top();
                st.pop();
            }

            if(i+1 < temperatures.size() && temperatures[i] < temperatures[i+1]) 
                nextWarmDays[i] = 1;
            else                                    
                st.push(i);
        }

        return nextWarmDays;
    }
};