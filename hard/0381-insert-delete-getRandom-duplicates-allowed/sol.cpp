#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class RandomizedCollection {
private:
    int tail;
    vector<int> arr;
    unordered_map<int,priority_queue<int>> mp;
    
public:
    RandomizedCollection() {
        tail = -1;
    }
    
    bool insert(int val) {
        bool res = mp.find(val)!=mp.end() && !mp[val].empty() ? false : true; 

        tail += 1;
        mp[val].push(tail);
        arr.push_back(val);

        return res;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end() && !mp[val].empty()) {
          int index = mp[val].top();
          mp[val].pop();

          if(tail != index) {
            mp[arr[tail]].pop();
            mp[arr[tail]].push(index);

            arr[index] ^= arr[tail];
            arr[tail] ^= arr[index];
            arr[index] ^= arr[tail];
          }

          arr.pop_back();
          tail -= 1;

          return true;
        }

        return false;
    }
    
    int getRandom() {
        return arr[rand() % (tail+1)];
    }
};
