#include <iostream>
#include <cstring>
#include "256trie_tree.h"
#include "FileOption.h"
#include <ctime>
using namespace std;

Node::Node(char ch){
    this -> ch = ch;
    memset(this->children, NULL, sizeof(this -> children));
}


TrieTree::TrieTree(){
    this -> root = new Node('0');
}

void TrieTree::insert(char* s){
    Node* t = this -> root;
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        char ch = s[i];
        int ch_idx = (int)ch;

        if(ch_idx < 0){
            ch_idx = 127 - ch;
        }
        if(t -> children[ch_idx] == NULL){
            t -> children[ch_idx] = new Node(ch);
        }
        
        t = t -> children[ch_idx];
    }
    t -> children[256] = new Node(1);

}

bool TrieTree::find(char* s){
    Node* t = this -> root;
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        char ch = s[i];
        int ch_idx = (int)ch;
        if(ch_idx < 0){
            ch_idx = 127 - ch;
        }
        if(t -> children[ch_idx] == NULL){
            return false;
        }

        t = t -> children[ch_idx];
    }
    if(t -> children[256] == NULL){
        return false;
    }


    return true;
}


int main(){

	clock_t start, finish;
	start = clock();

    TrieTree* tree = new TrieTree();
	FileReader* fr = new FileReader();
	char* fileLoc = { "./dict.txt" };
	bool openRe = fr->openFile(fileLoc,"r");
	if (openRe == false) {
		cout << "文件打开错误" << endl;
		system("pause");
		return 0;
	}
	char* data = new char[BUFFER_SIZE];
	memset(data, 0x00, BUFFER_SIZE);
	int idx = 0;
	while (fr->getline(data))
	{
		int length = strlen(data);
		if (length == 0) continue;
		char* m = new char[length+1];
		memcpy(m, data, length+1);
		tree->insert(m);
	}


	delete fr;


	FileReader* fr_target = new FileReader();
	fileLoc = { "./string.txt" };
	openRe = fr_target->openFile(fileLoc,"r");
	if (!openRe) {
		cout << "error happen when open target file" << endl;
		system("pause");
		return 0;
	}
	
	FileWriter* fw = new FileWriter();
	fileLoc = { "./test _result.txt" };
	openRe = fw->openFile(fileLoc, "w");
	if (!openRe) {
		cout << "error happen when open result file" << endl;
		system("pause");
		return 0;
	}

	
	memset(data, 0x00, BUFFER_SIZE);
	int i = 0;
	while (fr_target->getline(data))
	{
		int length = strlen(data);
		if (length == 0) continue;
		
		if (tree -> find(data)) {
			fw->putline(data);
			i++;
		}
	}
	delete fr_target;
	delete fw;
	finish = clock();
	cout<<i<<" lines matched"<<endl;
	cout << "use time  is " << finish - start << endl;

	system("pause");
	
	return 0;

}
