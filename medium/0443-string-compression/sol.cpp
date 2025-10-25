#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
      int left = 0, right = 0;
      int count = 0;

      for(;right<=chars.size();right+=1) {
        if(right==chars.size() || chars[right]!=chars[left]) {
          if(count > 1) {
            string str = to_string(count);
            for(int i=0;i<str.size();i+=1) {
              left += 1;
              chars[left] = str[i];
            }
          }
          if(right!=chars.size()) {
            left += 1;
            chars[left] = chars[right];
            count = 1;
          }
        }
        else 
          count += 1;
      }

      return left+1;
    }
};