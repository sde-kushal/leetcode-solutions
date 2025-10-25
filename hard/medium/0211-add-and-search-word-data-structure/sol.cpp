#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    bool end;
    vector<Trie*> nodes;

    Trie(): end(false), nodes(vector<Trie*>(26,nullptr)) {}
};

class WordDictionary {
private:
    Trie *root;
    string word;

    bool searchTrie(Trie *curr, int i) {
        if(!curr) return false;
        if(i==word.size())
            return curr->end;
        
        if(word[i] == '.') {
            for(int k=0;k<26;k+=1)
                if(searchTrie(curr->nodes[k],i+1))
                    return true;
            return false;
        }
        
        int index = static_cast<int>(word[i]) - 97;
        return searchTrie(curr->nodes[index],i+1);
    }

public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string insertWord) {
        Trie *ptr = root;
        for(int i=0;i<insertWord.size();i+=1) {
            int index = static_cast<int>(insertWord[i]) - 97;
            
            if(!(ptr->nodes[index])) 
                ptr->nodes[index] = new Trie();
            
            ptr = ptr->nodes[index];
            if(i == insertWord.size()-1)
                ptr->end = true;
        }    
    }
    
    bool search(string searchWord) {
        Trie *ptr = root;
        word = searchWord;
        return searchTrie(ptr,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */