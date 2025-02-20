#include <vector>
using namespace std;

class PeekingIterator : public Iterator {
private:
    vector<int> arr;
    int curr, n;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    arr = nums;
        curr = 0;
        n = nums.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return arr[curr];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        curr += 1;
	    return arr[curr-1];
	}
	
	bool hasNext() const {
	    return curr < n;
	}
};