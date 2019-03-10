#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string LoadFile();
void WriteFile(string data);

int main() {
	while (1) {
		cout << "请输入要写入到文件的内容：" << endl;
		string something;
		cin >> something;
		WriteFile(something);
		cout << "正在尝试读取文件内容：" << endl;
		cout << LoadFile();
	}
}

string LoadFile() {
	ifstream file;
	file.open("4thTeam.txt", ios::in);
	string data = "";
	if (file.is_open()) {
		while (!file.eof()) {
			string temp;
			file >> temp;
			data += (temp + '\n');
		}
	}
	else {
		file.close();
		return "错误：读取失败！文件未打开";
	}
	file.close();
	return data;
}

void WriteFile(string data) {
	ofstream file;
	file.open("4thTeam.txt", ios::app);
	if (file.is_open()) {
		file << data << endl;
	}
	else {
		cout << "错误：读取失败！文件未打开" << endl;
	}
	file.close();
}