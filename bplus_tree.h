#include <iostream>
#include <cstring>

using namespace std;

// class LeafListNode{
//     //叶子节点的链表节点
//     public:
//         char* val;
//         LeafListNode* next;
//         LeafListNode(char* val);
// };

// class IndexListNode{
//     //索引节点的链表节点
//     public:
//         unsigned int val;
//         IndexListNode* next;
//         IndexListNode(unsigned int val);
// };

class Node{
    public:
        int order;//树的阶
        int keynum;//当前关键字数量
        unsigned int* keys;//存储key(叶子节点和索引节点都存在key)
        bool isLeaf;//当前节点是否为叶子节点
        Node* parent;//存储当前节点的父亲节点
};

class IndexNode : public Node{
    //索引节点
    public:
        Node** children;//存储孩子节点的指针（指针数组）
        IndexNode(int order);
};

class LeafNode : public Node{
    //叶子节点
    public:
        Node* next;//存储叶子节点的下一个节点的指针
        char** values;//存储字符串数组
        LeafNode(int order);
};

class BPlusTree{
    private:
        int order;//树的阶
        Node* root;//树的根
    
    public:
        BPlusTree(int order);
        void insert(char* s, unsigned int key);//插入字符串s到叶子节点，key值可根据hash函数求出
        Node* search(char* s, unsigned int key);//找到字符串s在树中对应的叶子节点方便插入
        bool find(char* s);
        void printKeys();//输出所有的key
        void printValues();//输出所有values（字符串）
        ~BPlusTree();
};