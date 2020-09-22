#include <iostream>
#include <cstring>
#define hash_len 11003

unsigned int RSHash(char *str); 

struct ListNode {
	char* val;
	ListNode* next;
	ListNode() : val(NULL), next(NULL) {}
	ListNode(char* x) : val(x), next(NULL) {}
	ListNode(char* x, ListNode* next) : val(x), next(next) {}
};
struct HeadNode{
	int val;
	ListNode* next;
	HeadNode() : val(0), next(NULL){}
	HeadNode(int x) : val(x), next(NULL){}
};

class HashMap{
	private:
		HeadNode hash[hash_len];
		
	public:
		HashMap();
		int get(char* val);
		void put(char* val);
};
