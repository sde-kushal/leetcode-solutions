#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool validPermutaion(vector<int> a, vector<int> b) {
        for(int i=0;i<26;i+=1)
            if(a[i]!=b[i])  return false;
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())   
            return false;
        
        vector<int> original_freq(26,0);
        vector<int> window_freq(26,0);
        
        for(int i=0;i<s1.size();i+=1) {
            original_freq[static_cast<int>(s1[i])-97] += 1;
            window_freq[static_cast<int>(s2[i])-97] += 1;
        }

        int left = 0, right = s1.size()-1;

        for(;right<s2.size();right+=1,left+=1) {
            if(validPermutaion(original_freq,window_freq))
                return true;
            
            window_freq[static_cast<int>(s2[left])-97] -= 1;
            if(right+1 < s2.size())
                window_freq[static_cast<int>(s2[right+1])-97] += 1;
        }

        return false;
    }
};