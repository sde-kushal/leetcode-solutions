#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int k, int v): key(k), val(v), left(nullptr), right(nullptr) {}
    };

    Node *MRU, *LRU;
    int cap, curr;
    unordered_map<int,Node*> mp;

    void setToMostRecentlyUsed(Node *ptr) {
        if(ptr == MRU) return;
        if(ptr == LRU) {  // will also mean cap > 1
            LRU = LRU->left;
            LRU->right = nullptr;
            ptr->left = nullptr;
        }
        else {
            if(ptr->left)   ptr->left->right = ptr->right;
            if(ptr->right)  ptr->right->left = ptr->left;
            ptr->left = nullptr;
        }

        if(MRU) {
            ptr->right = MRU;
            MRU->left = ptr;
        }
        MRU = ptr;

        if(!LRU) LRU = MRU;
    }

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->curr = 0;
        this->MRU = this->LRU = nullptr;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()) {
            Node *temp = mp[key];
            setToMostRecentlyUsed(temp);
            return temp->val;       
        }
        return -1;
    }
    
    void put(int key, int value) {
        // updating existing key
        if(mp.find(key)!=mp.end()) {
            Node *temp = mp[key];
            temp->val = value;
            setToMostRecentlyUsed(temp);
        }

        // insert new key
        else {
            Node *newNode = new Node(key,value);
            setToMostRecentlyUsed(newNode);
            mp[key] = newNode;

            // increase curr size
            curr += 1;
            if(curr > cap) {
                // remove LRU
                Node *temp = LRU;
                LRU = LRU->left;
                if(cap > 1) LRU->right = nullptr;
                temp->left = nullptr;

                mp.erase(temp->key);
                delete temp;

                curr -= 1;
            }
        }
    }
};
