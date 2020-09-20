#include <iostream>
#include <cstring>
using namespace std;

//RShash映射函数 
unsigned int RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

//链表元素定义 
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

//hashmap 定义 
class HashMap{
	private:
		HeadNode hash[13];
		
	public:
		HashMap(){
			for(int i = 0;i < 13;i++){
				hash[i] = HeadNode();
			}
		}
		int get(char* val){
			int hashId = RSHash(val);
			hashId %= 13;
			HeadNode head = hash[hashId];
			ListNode* p = head.next;
			while(p != NULL){
				if(strcmp(p -> val, val) != 0){
					p++;
				}
				else{
					return 1;
				}
			} 
			
			return 0;
		}
		
		void put(char* val){
			int hashId = RSHash(val);
			hashId %= 13;
			HeadNode head = hash[hashId];
			ListNode* p = new ListNode(val);
			if(p == NULL){
				head.next = p;
			}
			else{
				p -> next = head.next;
				head.next = p;				
			}
		}
};
//int main(){
//	HashMap* map = new HashMap();
//	 
//	return 0;
//} 
