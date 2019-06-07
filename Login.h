#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include"Movie.h"
class LogIn{

private:
	static vector<string> csv_read_row(istream &file, char delimiter)
	{// csv �о���µ��� ����� ����. 
		stringstream ss;
		bool inquotes = false;
		vector<string> row;//relying on RVO

		while (file.good())
		{
			char c = file.get();
			if (!inquotes && c == '"')
			{
				inquotes = true;
			}
			else if (inquotes && c == '"')
			{
				if (file.peek() == '"')
				{
					ss << (char)file.get();
				}
				else
				{
					inquotes = false;
				}
			}
			else if (!inquotes && c == delimiter)
			{
				row.push_back(ss.str());
				ss.str("");
			}
			else if (!inquotes && (c == '\r' || c == '\n'))
			{
				if (file.peek() == '\n') { file.get(); }
				row.push_back(ss.str());
				return row;
			}
			else
			{
				ss << c;
			}
		}
	}
	vector<vector<string>> vctr; /////��ǻ� �о�� �����͸� ��� �����Ͽ� ���������� �����ؾ��ϴ� 2���� ����. 
	int userNum;// �ӽ÷� ����ϴ� ������ȣ
	int currentUserNum; // ���� ���� ��ȣ, �̸� �̿��Ͽ� ���� �α������� ������ �ĺ������� �ʴ´�.
	string tmpID; //���� ���� ID
	string currentUserID; // ���� ���� ID :: �� ������ �α��� ����! ������ȣ�� �������� �ʴ´�.
						  //���� ��ȣ�� �ƴ� ID�� �̿��Ͽ� �����ϴ� ������, ���� ������ ���� �۾��� �߰������� ������ ���,
						  //���� ��ȣ�� ������� �ϴµ�, �� ��Ȳ���� ��ȣ�� �����ϸ� ���� �� �־ ����������.
public:
	//Login �Լ���
	//�� ����� ��ŭ�� ����� �����Ѵ�.
	LogIn() {
		currentUserNum = 9999;
		currentUserID = "null";
	}
	bool idEqual(string str) {
		tmpID = "null";
		for (unsigned int i = 0; i < vctr.size(); i++) {
			if (str == vctr[i][1]) { //1�� �ڸ��� ID�� �Է��ϱ⿡ �̿� ���� �ۼ�
				tmpID = str;
				userNum = i;
				return true;
			}
		}
		if (tmpID == "null") {
			cout << "ID�� ����." << endl;
			return false;
		}
	}
	bool pwEqual(string str) {
		if (str != vctr[userNum][2]) {
			cout << "PW�� �ٸ���." << endl;
			return false;
		}
		else {
			return true;
		}

	}
	void doLogin(string str1, string str2) {
		if (idEqual(str1) == true && pwEqual(str2) == true) {
			currentUserNum = userNum; //////////user ID�� �����Ѵ�..... num���� �ϸ�, �����ÿ� �ſ� �ǰ�������.
			currentUserID = vectorRead(currentUserNum, "ID");
			cout << "�α����մϴ�." << endl;
			cout << "���� ��ȣ : " << currentUserNum << " ID : " << vctr[userNum][1] << " PW : " << vctr[userNum][2] << endl;
			cout << "���� �α��ε� ID : " << currentUserID << endl;

		}
		else {
			cout << "�α��� ���� �Ҹ���" << endl;
		}

	}
	void logOut() {
		cout << "���� ������ȣ : " << currentUserNum << endl;
		cout << "�α׾ƿ�" << endl;
		currentUserNum = 9999;
		currentUserID = "null";

		//cout << "���� ������ȣ : " << currentUserNum << endl;
	}
	void idRegister(string id, string pw) {  ///////////////ȸ������! ������ȣ, ID, PW�� ���ڷ� �ִ´�
		if (idEqual(id) == true) {
			cout << "�ߺ��� ���̵��Դϴ�." << endl;

		}
		else {
			vector<string> vct;
			string tmpstr = "";
			tmpstr = to_string(vctr.size() + 1);  ////int string ����ȯ!
			cout << (int)vctr.size() << tmpstr << endl;
			vct.push_back(tmpstr);
			vct.push_back(id);
			vct.push_back(pw);
			vctr.push_back(vct);
			writeDemo();
		}

	}
	void readDemo() { ///////////// ������� :: User.csv���� �о�ͼ� ���Ϳ� �־������.
					  //ifstream�� ������ �а� ���ִ� �Լ��ν� ifstream (���ϸ� or ���)
		ifstream file("Users2.csv");

		if (file.fail())  //���� bad() �Լ��� ���� �ϸ�..
		{
			cout << "�ش� ��ο� ��ġ�ϴ� ������ �������� �ʽ��ϴ�." << endl;
		}



		while (file.good()) //eof, bad, fail �Լ��� ������ ���� ��ȯ�� ������..
		{
			vector<string> row = csv_read_row(file, ',');

			if (!row[0].find("#")) //���� csv ���� �ȿ� # ���ڰ� �������
			{
				continue; //�׳� �ǳ� �پ��
			}
			else //#���ڰ� ���� ���
			{
				for (int i = 0, leng = row.size(); i < leng; i++)
				{
					cout << "[" << row[i] << "]" << "\t"; //�˸°� ���


				}
				cout << endl;

				vctr.push_back(row); //�ᱹ ������ ���Ϳ� ����
			}


		}
		file.close();

	}
	void writeDemo() {  //////////�����Է� :: ������ ���͸� �������� �����Ѵ�
						//ifstream�� ������ �а� ���ִ� �Լ��ν� ifstream (���ϸ� or ���)
		ofstream file("Users2.csv");

		if (file.fail())  //���� bad() �Լ��� ���� �ϸ�..
		{
			cout << "�ش� ��ο� ��ġ�ϴ� ������ �������� �ʽ��ϴ�." << endl;
		}


		for (unsigned int i = 0; i < vctr.size(); i++) {
			string str = "";
			for (unsigned int j = 0; j < vctr[i].size(); j++) {
				str += vctr[i][j];
				if (j != vctr[i].size() - 1)
					str += ",";
			}

			file << str << "\n";
			cout << str << endl;

		}




		file.close();
	}
	void vectorEdit(int num, string str1, string str2) { //// DB�� ���ٹ� ����
														 //num�� ����, str1�Ӽ��� str2������ �ٲ۴�.
														 //ex) vectorEdit(3, "ID", "��Ǹ�") -> 3�� ���� ID�� ��Ǹ�� �ٲ۴�.
		int tmpnum = 77474; // ������ �񱳸� ���� ��.. �����Ƽ� ���� �̷��� ����
		for (unsigned int i = 0; i < vctr[0].size(); i++) {
			//cout << "���� ���Ҹ� : " << vctr[0][i] << endl;
			if (vctr[0][i] == str1) {
				tmpnum = i;
			}
		}
		if (tmpnum == 77474) {
			cout << str1 << ", �׷� ���Ҵ� ����." << endl;
		}
		else {
			vctr[num][tmpnum] = str2;
		}

	}
	string vectorRead(int num, string str) {
		int tmpnum = 77474;
		for (unsigned int i = 0; i < vctr[0].size(); i++) {
			//cout << "���� ���Ҹ� : " << vctr[0][i] << endl;
			if (vctr[0][i] == str) {
				tmpnum = i;
			}
		}
		return vctr[num][tmpnum];


	}
};