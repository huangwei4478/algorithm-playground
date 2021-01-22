//
//  Trie.hpp
//  liuyubobobo_trie
//
//  Created by huangwei on 2021/1/22.
//

#ifndef Trie_hpp
#define Trie_hpp


// leetcode 208, implement trie
// leetcode 211,
// leetcode 677


#include <unordered_map>
#include <string>

using namespace std;

class Trie {
public:
    Trie() {
        _root = new Node();
        _size = 0;
    }
    
    ~Trie() {
        // todo: delete every Node in subnodes
        delete _root;
    }
    
    int size() {
        return _size;
    }
    
    // insert a new word into trie
    void add(string word) {
        Node* cur = _root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur -> next.count(c) == 0) {
                cur -> next[c] = new Node();
            }
            cur = cur -> next[c];
        }
        
        if (!cur -> isWord) {
            cur -> isWord = true;
            _size++;
        }
    }
    
    // check if word is in the trie
    bool contains(string word) {
        Node* cur = _root;
        
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur -> next.count(c) == 0) {
                return false;
            }
            cur = cur -> next[c];
        }
        
        return cur -> isWord;
    }
    
    // check if there is a word that starts with this prefix
    bool isPrefix(string prefix) {
        Node* cur = _root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if (cur -> next.count(c) == 0) {
                return false;
            }
            cur = cur -> next[c];
        }
        
        return true;
    }
    
    
private:
    class Node {
    public:
        // char c;
        bool isWord;
        unordered_map<char, Node*> next;
        
        Node() : isWord { false } {}
        Node(bool isWord) : isWord { isWord } {}
    };
    
    Node* _root;
    int _size;
};

#endif /* Trie_hpp */
