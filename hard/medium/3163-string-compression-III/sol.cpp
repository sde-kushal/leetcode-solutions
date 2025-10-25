#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
      string comp = "";
      int count = 1;
      char curr = word[0];

      for(int i=1;i<word.size();i+=1)
        if(count==9 || curr!=word[i]) {
          comp += (char)('0'+count);
          comp += curr;
          count = 1;
          curr = word[i];
        }
        else
          count += 1;

      comp += (char)('0'+count);
      comp += curr;
      return comp;
    }
}; 