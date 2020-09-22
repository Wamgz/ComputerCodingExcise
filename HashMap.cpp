#include "HashMap.h"
using namespace std;

unsigned int RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str){
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}


HashMap::HashMap(){
	for(int i = 0;i < hash_len;i++){
		hash[i] = HeadNode();
	}
}

int HashMap::get(char* val){
	int hashId = RSHash(val);
	hashId %= hash_len;
	HeadNode head = hash[hashId];
	ListNode* p = head.next;

	while(p != NULL){
		if(strcmp(p -> val, val) != 0){
			p = p -> next;
		}
		else{
			return 1;
		}
	} 	
	return 0;
}
		
void HashMap::put(char* val){
	int hashId = RSHash(val);
	hashId %= hash_len;
	
	HeadNode* head = &hash[hashId];

	if(head -> next == NULL){
		head -> next = new ListNode(val);
	}
	else{
		ListNode* p = head -> next; 
			
		while(p -> next != NULL){
			p = p -> next;
		}
		p -> next = new ListNode(val);	
	}
}

int main(){
	HashMap* map = new HashMap();
	FileReader* fr = new FileReader();
	char* fileLoc = { "D:/Programming/C++/计算机应用编程实验/test_source.txt" };
	bool openRe = fr->openFile(fileLoc,"r");
	if (openRe == false) {
		cout << "文件打开错误" << endl;
		system("pause");
		return 0;
	}
	char* data = new char[BUFFER_SIZE];
	memset(data, 0x00, BUFFER_SIZE);
	while (fr->getline(data))
	{
		int length = strlen(data);
		if (length == 0) continue;
		char* m = new char[length+1];
		memcpy(m, data, length+1);
		map->put(m);
	}
	delete fr;

	FileReader* fr_target = new FileReader();
	fileLoc = { "D:/Programming/C++/计算机应用编程实验/test _target.txt" };
	openRe = fr_target->openFile(fileLoc,"r");
	if (!openRe) {
		cout << "error happen when open target file" << endl;
		system("pause");
		return 0;
	}
	
	FileWriter* fw = new FileWriter();
	fileLoc = { "D:/Programming/C++/计算机应用编程实验/test _result.txt" };
	openRe = fw->openFile(fileLoc, "w");
	if (!openRe) {
		cout << "error happen when open result file" << endl;
		system("pause");
		return 0;
	}

	
	memset(data, 0x00, BUFFER_SIZE);
	while (fr_target->getline(data))
	{
		int length = strlen(data);
		if (length == 0) continue;
		if (map->get(data)) {
			cout << data << endl;
			fw->putline(data);
		}
	}
	delete fr_target;
	delete fw;
	system("pause");
	return 0;
}
