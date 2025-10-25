#include <utility>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    using Coords = pair<int,int>;
    using CustomHeap = pair<int,Coords>;

    struct MinHeapCompare {
        bool operator()(const CustomHeap &a, const CustomHeap &b) {
            return a.first > b.first;
        }
    };

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> visited;
        int kth_smallest_index = 0;
        priority_queue<CustomHeap, vector<CustomHeap>, MinHeapCompare> heap;

        int rows = matrix.size(),
            cols = matrix[0].size();
        int curr_row = 0,
            curr_col = 0;

        heap.push(make_pair(matrix[curr_row][curr_col], make_pair(curr_row,curr_col)));
        while(!heap.empty() && kth_smallest_index < k) {
            CustomHeap curr = heap.top();
            int curr_value = curr.first;
            Coords curr_coords = curr.second;

            if(curr_coords.first + 1 < rows) {
                heap.push(make_pair(matrix[curr_coords.first + 1][curr_coords.second],make_pair(curr_coords.first + 1, curr_coords.second)));
            }
            
            if(curr_coords.second + 1 < cols) {
                heap.push(make_pair(matrix[curr_coords.first][curr_coords.second + 1],make_pair(curr_coords.first, curr_coords.second + 1)));
            }

            visited.push_back(curr_value);
            kth_smallest_index++;
            heap.pop();
        }

        return visited[kth_smallest_index - 1];
    }
};