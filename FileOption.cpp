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
			if (!feof(fp)) {
				fgets(this->buffer,BUFFER_SIZE,this->fp);
				this->buffer[strlen(this->buffer)-1] = '\0';
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

class FileWriter {
private:
	FILE* fp;
public:
	FileWriter() {
		this->fp = NULL;
	}

	bool openFile(char* fileLoca, char* readMode) {
		this->fp =	 fopen(fileLoca, readMode);
		if (this->fp == NULL)
			return false;
		else
			return true;
	}

	bool putline(char* data) {
		if (this->fp == NULL) return false;
		else {
			int putResult = 0;
			putResult= fputs(data,this->fp);
			if (putResult == EOF) return false;
			putResult = fputs("\n", this->fp);
			if (putResult == EOF) return false;
		}
		return true;
	}


	~FileWriter() {
		if (this->fp == NULL)
			fclose(this->fp);
	}
};

//int main() {
//文件读取测试
//	FileReader* f = new FileReader();
//	bool openResult= f->openFile("D:/Programming/C++/计算机应用编程实验/test.txt", "r");
//	if (openResult == NULL) {
//		cout << "error happen" << endl;
//	}
//	else {
//		char* data = new char[BUFFER_SIZE];
//		for (int i = 0; i < 1000; i++) {
//			if (f->getline(data)) {
//				cout << i << ":" << data << endl;;
//			}
//		}
//	}
//	
//	system("pause");
//	return 0;
//}

int main() {
//文件读取测试
	FileWriter* f = new FileWriter();
	bool openResult= f->openFile("D:/Programming/C++/计算机应用编程实验/writetest.txt", "w");
	if (openResult == NULL) {
		cout << "error happen" << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			char* a = new char[100];
			a[0] = i;
			if (!f->putline(a))
				cout << "error happen" << endl;
		}
	}
	
	system("pause");
	return 0;
}