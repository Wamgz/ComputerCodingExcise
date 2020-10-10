#include"FileOption.h"

using namespace std;


FileReader::FileReader() {
		fp = NULL;
		memset(buffer, 0x00, BUFFER_SIZE);
	}

bool FileReader::openFile(char* fileLoca, char* readMode) {
		this->fp = fopen(fileLoca, readMode);
		if (this->fp == NULL)
			return false;
		else
			return true;
	}

bool FileReader::getline(char* data) {
		//当文件打开失败时使用读取直接返回空
		if (fp == NULL) return false;
		else {
			if (!feof(fp)) {
				fgets(this->buffer,BUFFER_SIZE,this->fp);
				if(this->buffer[strlen(this->buffer) - 1] == '\n')
					this->buffer[strlen(this->buffer)-1] = '\0';
				memcpy(data, this->buffer, sizeof(this->buffer)/sizeof(char));
				memset(data, 0x00, BUFFER_SIZE);
				return true;
			}
			else return false;
		}
	}

FileReader::~FileReader() {
		if (this->fp != NULL)
			fclose(fp);
	}

FileWriter::FileWriter() {
		this->fp = NULL;
	}

bool FileWriter::openFile(char* fileLoca, char* readMode) {
		this->fp =	 fopen(fileLoca, readMode);
		if (this->fp == NULL)
			return false;
		else
			return true;
	}

bool FileWriter::putline(char* data) {
	//putlien，效果类似于println，对于data 存在要求，使用\n 或者\0标记末尾
	if (this->fp == NULL) return false;
	else {
		int putResult = 0;
		putResult = fputs(data, this->fp);
		if (putResult == EOF) return false;
		putResult = fputs("\n", this->fp);
		if (putResult == EOF) return false;
	}
	return true;
}

FileWriter::~FileWriter() {
		if (this->fp == NULL)
			fclose(this->fp);
	}

