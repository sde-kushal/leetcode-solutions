#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Trie {
public:
    bool end;
    unordered_map<string,Trie*> nodes;

    Trie(): end(false) {}
};

class Solution {
private:
    Trie *root;
    vector<string> rootFolders;

    void insertIntoTrie(string path) {
        string folder = "";
        path = path.append("/");
        Trie *curr = root;

        for(int i=1;i<path.size();i+=1) {
            if(path[i] == '/') {
                if(curr->end)
                    return;
                
                bool isEnd = i == path.size()-1 ? true : false;
                
                if(curr->nodes.find(folder)==curr->nodes.end())
                    curr->nodes[folder] = new Trie();
                    if(isEnd) {
                        curr = curr->nodes[folder];
                        curr->end = true;
                    }

                else {
                    curr = curr->nodes[folder];
                    if(isEnd) 
                        curr->end = true;
                }

                folder = "";
            }
            else 
                folder += path[i];
        }
    }

    void readFolders(Trie *curr, string path) {
        if(!curr) return;
        if(curr->end) {
            rootFolders.push_back(path);
            return;
        }

        for(auto it=curr->nodes.begin();it!=curr->nodes.end();it++)
            readFolders(it->second, path + "/" + it->first);
    }

public:
    Solution() { 
        root = new Trie(); 
        rootFolders = vector<string>();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        for(int i=0;i<folder.size();i+=1)
            insertIntoTrie(folder[i]);
        
        readFolders(root,"");
        return rootFolders;
    }
};