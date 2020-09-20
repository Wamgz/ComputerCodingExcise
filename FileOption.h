#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define BUFFER_SIZE 150


class FileReader {
private:
	FILE* fp;
	char buffer[BUFFER_SIZE];

public:
	FileReader();
	bool openFile(char* fileLoca, char* readMode);
	bool getline(char* data);

	~FileReader();
};

class FileWriter {
private:
	FILE* fp;
public:
	FileWriter();
	bool openFile(char* fileLoca, char* readMode);
	bool putline(char* data);
	~FileWriter();
};