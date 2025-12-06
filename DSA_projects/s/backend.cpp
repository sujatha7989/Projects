#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(char c : word) {
            int index = c - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }
        return node->isEnd;
    }
};

// Word list
string dictWords[] = {
    "apple","ball","cat","car","carry","book","dog","hat","mango","nest","pen"
};

int main(int argc, char* argv[]) {
    Trie trie;

    for(string w : dictWords)
        trie.insert(w);

    if(argc < 2) {
        cout << "ERROR";
        return 0;
    }

    string query = argv[1];

    if(trie.search(query))
        cout << "FOUND";
    else
        cout << "NOT_FOUND";

    return 0;
}
