#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> store;
        int x;

        for(int i=0;i<arr.size();i+=1) {
            if(arr[i]>=0)   x = arr[i]%k;
            else            x = -1 * (abs(arr[i])%k);
            
            if(store.find(x)!=store.end())  store[x] += 1;
            else                            store[x] = 1;
        }
        
        for(int i=0;i<arr.size();i+=1) {
            if(arr[i]>=0)   x = arr[i]%k;
            else            x = -1 * (abs(arr[i])%k);

            if(x>0 && store[x] > 0) {
                if(store.find(-1*x)!=store.end() && store[-1*x]>0) {
                    store[x] -= 1;
                    store[-1*x] -= 1;
                }
                else if(store.find(k-(x%k))!=store.end() && store[k-(x%k)]>0) {
                    store[x] -= 1;
                    store[k-(x%k)] -= 1;
                }
                else    return false;
            }

            else if(x<0 && store[x]>0) {
                if(store.find(abs(x))!=store.end() && store[abs(x)]>0) {
                    store[x] -= 1;
                    store[abs(x)] -= 1;
                }
                else if(store.find(-1*(k-(abs(x)%k)))!=store.end() && store[-1*(k-(abs(x)%k))]>0) {
                    store[x] -= 1;
                    store[-1*(k-(abs(x)%k))] -= 1;
                }
                else    return false;
            }

            else if(x==0 && store[x]>0)
                if(store[x] > 1)    store[x] -= 2;
                else                return false;
        }

        return true;
    }
};