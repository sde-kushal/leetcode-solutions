#include <vector>
#include <limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int valueToInsert(ListNode*& head) {
        if(!head) return -1;
        
        int value = head->val;
        head = head->next;
        return value;
    }

    void getNextCoords(vector<int> &coords, int &top, int &bottom, int &left, int &right, int m, int n, int &directions) {
        switch(directions) {
            case 0:
                // top
                if(coords[1] == n-right-1) {
                    coords = { coords[0] + 1, coords[1] };
                    top += 1;
                    directions = (directions + 1) % 4;
                    return;
                }
                else {
                    coords = { coords[0], coords[1] + 1 };
                    return;
                }

            case 1:
                // right
                if(coords[0] == m-bottom-1) {
                    coords = { coords[0], coords[1] - 1 };
                    right += 1;
                    directions = (directions + 1) % 4;
                    return;
                }
                else {
                    coords = { coords[0] + 1, coords[1] };
                    return;
                }

            case 2:
                // bottom
                if(coords[1] == left) {
                    coords = { coords[0] - 1, coords[1] };
                    bottom += 1;
                    directions = (directions + 1) % 4;
                    return;
                }
                else {
                    coords = { coords[0], coords[1] - 1 };
                    return;
                }

            case 3:
                // left
                if(coords[0] == top) {
                    coords = { coords[0], coords[1] + 1 };
                    left += 1;
                    directions = (directions + 1) % 4;
                    return;
                }
                else {
                    coords = { coords[0] - 1, coords[1] };
                    return;
                }
        }
    }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, INT_MIN));
        vector<int> curr = {0,0};
        int top_wall = 0,
            right_wall = 0,
            bottom_wall = 0,
            left_wall = 0;
        int total_visited = 0;
        int directions = 0;

        while(total_visited < m*n && matrix[curr[0]][curr[1]] == INT_MIN) {
            int value = valueToInsert(head);
            matrix[curr[0]][curr[1]] = value;

            getNextCoords(curr, top_wall, bottom_wall, left_wall, right_wall, m, n, directions);

            total_visited++;
        }

        return matrix;
    }
};