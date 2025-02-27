#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    int lc, rc;

public:
    MedianFinder() {
        lc = rc = 0;    
    }
    
    void addNum(int num) {
        if(lc == rc) {
            if(lc == 0 || num <= rightHeap.top()) {
                leftHeap.push(num);
                lc += 1;
            }
            else {
                rightHeap.push(num);
                rc += 1;
            }
        }

        else if(lc > rc) {
            if(num >= leftHeap.top()) {
                rightHeap.push(num);
                rc += 1;
            }
            else {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
                rc += 1;
            }
        }

        else {
            if(num <= rightHeap.top()) {
                leftHeap.push(num);
                lc += 1;
            }
            else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
                lc += 1;
            }
        }
    }
    
    double findMedian() {
        if(lc == rc)
            return (leftHeap.top() + rightHeap.top()) / 2.0;
        return lc > rc ? leftHeap.top() : rightHeap.top();
    }
};