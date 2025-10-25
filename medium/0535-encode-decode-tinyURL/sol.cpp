#include <unordered_map>
#include <string>
using namespace std;

class Solution {
unordered_map<string,string> enc, dec;

string generateRandom(int len) {
    string r = "";
    int random;
    
    for(int i=0;i<len;i+=1){
        random = rand() % 62;
        if(random < 10)
            r += to_string(random);
        else if(random >= 10 && random < 36)
            r += static_cast<char>(random+55);
        else if(random >= 36 && random < 62)
            r += static_cast<char>(random+61);
    }

    return r;
}

public:
    string encode(string longUrl) {
        if(dec.find(longUrl)!=dec.end())
            return dec[longUrl];
        else {
            string r = "https://" + generateRandom(4);
            while(enc.find(r)!=enc.end())
                r = "https://" + generateRandom(4);

            enc[r] = longUrl;
            dec[longUrl] = r;
            return r;
        }        
    }

    string decode(string shortUrl) {
        if(enc.find(shortUrl)!=enc.end())
            return enc[shortUrl];
        return "";        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));