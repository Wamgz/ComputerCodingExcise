#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define BUFFER_SIZE 150
using namespace std;
class FileReader {
private:
	FILE* fp;
	char buffer[BUFFER_SIZE];

public:
	FileReader() {
		fp = NULL;
		memset(buffer, 0x00, BUFFER_SIZE);
	}

	bool openFile(char* fileLoca, char* readMode) {
		this->fp = fopen(fileLoca, readMode);
		if (this->fp == NULL)
			return false;
		else
			return true;
	}

	bool getline(char* data) {
		//当文件打开失败时使用读取直接返回空
		if (fp == NULL) return false;
		else {
			int notEOF =fscanf(this->fp,"%s",this->buffer );
			if (notEOF != EOF) {
				memcpy(data, this->buffer, sizeof(this->buffer)/sizeof(char));
				return true;
			}
			else return false;
		}
	}

	~FileReader() {
		if (this->fp != NULL)
			fclose(fp);
	}
};

int main() {
	FileReader* f = new FileReader();
	bool openResult= f->openFile("D:/Programming/C++/计算机应用编程实验/dict.txt", "r");
	if (openResult == NULL) {
		cout << "error happen" << endl;
	}
	else {
		char* data = new char[BUFFER_SIZE];
		for (int i = 0; i < 1000; i++) {
			if (f->getline(data)) {
				cout << data << endl;
			}
		}
	}
	
	system("pause");
	return 0;
}