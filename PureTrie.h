#ifndef PURE_TRIE_H
#define PURE_TRIE_H
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    vector<Node*> children() { return mChildren; }

private:
    char mContent;	//no idea why this apparently works for 2byte chars
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s) const;
    void deleteWord(string s);
    //bool char_by_char(string s) const;
private:
    Node* root;
};

#endif
