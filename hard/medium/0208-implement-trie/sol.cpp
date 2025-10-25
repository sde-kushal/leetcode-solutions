#include <vector>
using namespace std;

class Trie {
private:
    struct TrieNode {
      bool end;
      vector<TrieNode*> next;

      TrieNode(): end(false), next(vector<TrieNode*>(26,nullptr)) {};
    };

    TrieNode *head;

    TrieNode* searchWord(string word) {
        TrieNode *ptr = head;

        for(int i=0;i<word.size();i+=1) {
            int index = static_cast<int>(word[i]) - 97;

            if(!ptr->next[index])
                return nullptr;
            
            ptr = ptr->next[index];
        }
        
        return ptr;
    }

public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *ptr = head;

        for(int i=0;i<word.size();i+=1) {
            int index = static_cast<int>(word[i]) - 97;
            
            if(!ptr->next[index]) 
                ptr->next[index] = new TrieNode();
            
            ptr=ptr->next[index];

            if(i==word.size()-1)
                ptr->end = true;
        }
    }
    
    bool search(string word) {
        TrieNode *ptr = searchWord(word);
        return ptr ? ptr->end : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *ptr = searchWord(prefix);
        return ptr ? true : false;
    }
};