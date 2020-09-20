#include"FileOption.h"
using namespace std;

//int main() {
////文件读取测试
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

//文件写入测试
int main() {
//文件读取测试
	FileWriter* f = new FileWriter();
	bool openResult= f->openFile("D:/Programming/C++/计算机应用编程实验/writetest.txt", "w");
	if (openResult == NULL) {
		cout << "error happen" << endl;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!f->putline("10001    10"))
				cout << "error happen" << endl;
		}
	}
	return 0;
}