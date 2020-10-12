#include <iostream>
using namespace std;

class Node{
    public:
        char ch;
        Node* children[257];
        Node(char ch);
};


class TrieTree{
    public:
        Node* root;
        TrieTree();
        void insert(char* s);
        bool find(char* s);
        ~TrieTree();
};
