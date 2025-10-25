#include <queue>
#include <unordered_set>
using namespace std;

class SmallestInfiniteSet {
private:
    struct Compare {
        bool operator()(const int &a, const int &b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, Compare> heap;
    unordered_set<int> infSet;

public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i+=1) {
            infSet.insert(i);
            heap.push(i);
        }
    }
    
    int popSmallest() {
        if(!heap.empty()) {
            int smallest = heap.top();
            heap.pop();
            infSet.erase(smallest);
            return smallest;
        }
        else
            return -1;
    }
    
    void addBack(int num) {
        if(infSet.count(num))
            return;
        
        infSet.insert(num);
        heap.push(num);
    }
};
