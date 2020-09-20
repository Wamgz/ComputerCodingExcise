#include"FileOption.h"

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
		//���ļ���ʧ��ʱʹ�ö�ȡֱ�ӷ��ؿ�
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
		//putlien��Ч��������println������data ����Ҫ��ʹ��\n ����\0���ĩβ
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

