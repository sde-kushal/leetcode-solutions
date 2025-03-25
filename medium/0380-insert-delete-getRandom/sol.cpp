#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
private:
    int n;
    vector<int> arr;
    unordered_map<int,int> mp;

public:
    RandomizedSet() {
        n = 0;
        arr = vector<int>();
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;

        mp[val] = n;
        n += 1;
        arr.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        
        int index = mp[val];
        mp[arr[n-1]] = index;

        arr[index] ^= arr[n-1];
        arr[n-1] ^= arr[index];
        arr[index] ^= arr[n-1];
        arr.pop_back();

        n -= 1;
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        return arr[rand() % n];
    }
};
    