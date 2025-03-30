#include <vector>
using namespace std;

class Solution {
private:
    struct Node {
        int val, index;
        Node *left, *right;
        Node(int x, int i): val(x), index(i), left(nullptr), right(nullptr) {}
    };

    Node *head, *tail;

    void insertIntoList(int val, int i) {
        // add as new node
        if(!head) {
            head = new Node(val, i);
            tail = head;
        }
        // add to top
        else if(val >= head->val) {
            head->val = val;
            head->index = i;
            head->right = nullptr;
            tail = head;
        }
        // add to end
        else if(val <= tail->val) {
            tail->right = new Node(val, i);
            tail->right->left = tail;
            tail = tail->right;
        }
        // sort into the list after finding the position
        else {
            Node *ptr = head;
            while(ptr->val > val)
                ptr = ptr->right;
            Node *temp = new Node(val, i);
            temp->left = ptr->left;
            ptr->left->right = temp;
            ptr->left = nullptr;
            tail = temp;
        }
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxIndex = 0, curr = 0;
        vector<int> ans(nums.size()-k+1, 0);
        
        for(int i=0;i<k;i+=1)
            if(nums[maxIndex] <= nums[i])
                maxIndex = i;

        ans[curr++] = nums[maxIndex];
        insertIntoList(nums[maxIndex], maxIndex);

        for(int i=maxIndex;i<k;i+=1)
            insertIntoList(nums[i], i);

        for(int i=1;i+k-1<nums.size();i+=1) {
            int outgoing = nums[i-1];
            int incoming = nums[i+k-1];

            if(outgoing == head->val && i-1 == head->index) {
                if(head == tail) 
                    tail = tail->right;
                Node *temp = head;
                head = head->right;
                if(head) {
                    temp->right = nullptr;
                    head->left = nullptr;
                }
                delete temp;
            }

            insertIntoList(incoming, i+k-1);

            ans[curr++] = head->val;
        }

        return ans;
    }
};