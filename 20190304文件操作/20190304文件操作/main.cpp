#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string LoadFile();
void WriteFile(string data);

int main() {
	while (1) {
		cout << "������Ҫд�뵽�ļ������ݣ�" << endl;
		string something;
		cin >> something;
		WriteFile(something);
		cout << "���ڳ��Զ�ȡ�ļ����ݣ�" << endl;
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
		return "���󣺶�ȡʧ�ܣ��ļ�δ��";
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
		cout << "���󣺶�ȡʧ�ܣ��ļ�δ��" << endl;
	}
	file.close();
}