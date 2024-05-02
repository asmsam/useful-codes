//Trie code

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_NODES 26

class Trie {
    public :
    int leaf_count;
    
    struct Node {
        vector<Node*> nList{vector<Node*>(MAX_NODES,nullptr)};
        bool is_leaf;
    }*root;
    
    Trie() {
        root = new Node();
        root->is_leaf = false;
        leaf_count=1;
    }

    bool search(Node* cur, string x, int i) {
        while(cur->nList[(int)x[i]-'a'] != nullptr) {
            if(i==x.size()-1 && cur->nList[(int)x[i]-'a']->is_leaf) {
                return true;
            }
            cur = cur->nList[(int)x[i]-'a'];
            i++;
        }
        return false;
    }
    
    void insert(Node* cur, string x, int i) {
        while(i<=x.size()-1) {
            cout << "at " << x[i] << endl;
            if(cur->nList[(int)x[i]-'a'] == nullptr) {
                cur->nList[(int)x[i]-'a'] = new Node();
                cout << "added" << endl;
            }
            cur = cur->nList[(int)x[i]-'a'];
            i++;
        }
        if(!cur->is_leaf) {
            cur->is_leaf = true;
            leaf_count++;
        }
    }
};

int main() {
    Trie t;
    t.insert(t.root, "asdf", 0);
    //cout << t.root->let << t.root->nList[0]->let;
    t.insert(t.root, "asef", 0);
    t.insert(t.root, "ased", 0);
    cout << t.search(t.root, "asdf", 0);
    return 0;
}