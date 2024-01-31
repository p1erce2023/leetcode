#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Node {
public:
    vector<Node*> c;
    bool e;
    Node():e(false),c(vector<Node*>(26, NULL)) {}
};

class WordDictionary {
public:
    Node trie;
    WordDictionary() {
        trie = Node();
    }

    void addWord(string word) {
        Node* t = &trie;
        for (char x : word) {
            int idx = x - 'a';
            if (! t->c[idx]) {
                t->c[idx] = new Node();
                t = t->c[idx];
            } else {
                t = t->c[idx];
            }
        }
        t->e = true;
    }

    bool search(string& word, int st, Node* p) {
        if (st == word.size()) {
            return p->e;
        } else {
            if (word[st] != '.') {
                int idx = word[st] - 'a';
                if (p->c[idx]) return search(word, st + 1, p->c[idx]);
                else return false;
            } else {
                for (auto pp : p->c) {
                    if (pp && search(word, st + 1, pp)) {
                        return true;
                    }
                }
                return false;
            }
        }
    }

    bool search(string word) {
        return search(word, 0, &trie);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    std::cout << obj->search("pad") << std::endl;
    std::cout << obj->search("bad") << std::endl;
    std::cout << obj->search(".ad") << std::endl;
    std::cout << obj->search("b..") << std::endl;
    return 0;
}