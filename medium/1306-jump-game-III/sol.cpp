#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)
            return true;

        queue<int> Q;
        unordered_set<int> visited;

        Q.push(start);
        visited.insert(start);

        while(!Q.empty()) {
            int index = Q.front();
            
            if(arr[index] == 0)
                return true;

            Q.pop();

            if(index + arr[index] < arr.size() && !visited.count(index + arr[index])) {
                Q.push(index+arr[index]);
                visited.insert(index+arr[index]);
            }
            if(index - arr[index] >= 0 && !visited.count(index - arr[index])) {
                Q.push(index-arr[index]);
                visited.insert(index-arr[index]);
            }
        }

        return false;
    }
};