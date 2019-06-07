#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include"Movie.h"
/*
객체 생성 -> 파일 이름을 인자로 던져준다.
객체 생성과 동시에 초기화함.(readDemo)
writeDemo() : csv 파일에 입력해줌(손볼필요 X)
vectorEdit(int num, string str1, string str2) : 벡터 수정 및 파일에 저장
num 번 row의, str1 속성을, str2로 바꾼다. 그 후, writeDemo()를 실행해 파일입력.
vectorRead(int num, string str) : 벡터에서 해당 값을 읽어옴
num 번 row의, str 속성을 리턴한다.

*/




class CSVEdit {

private:
	static vector<string> csv_read_row(istream &file, char delimiter)
	{// csv 읽어오는데에 사용한 벡터. 
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
	vector<vector<string>> vctr; /////사실상 읽어온 데이터를 모두 저장하여 전반적으로 관리해야하는 2차원 벡터. 
	int userNum;// 임시로 사용하는 유저번호
	int currentUserNum; // 현재 유저 번호, 이를 이용하여 현재 로그인중인 유저를 식별하지는 않는다.
	string tmpID; //임지 유저 ID
	string currentUserID; // 현재 유저 ID :: 이 변수로 로그인 관리! 유저번호로 관리하지 않는다.
						  //유저 번호가 아닌 ID를 이용하여 관리하는 이유는, 유저 삭제와 같은 작업을 추가적으로 구현할 경우,
						  //유저 번호가 당겨져야 하는데, 이 상황에서 번호로 관리하면 꼬일 수 있어서 귀찮아진다.
	string filename;
public:
	CSVEdit(string str) {
		filename = str;
		readDemo();
	}
	void readDemo() { ///////////// 파일출력 :: 파일에서 읽어와서 벡터에 넣어버린다.
					  //ifstream은 파일을 읽게 해주는 함수로써 ifstream (파일명 or 경로)
		ifstream file(filename);

		if (file.fail())  //만약 bad() 함수가 실패 하면..
		{
			cout << "해당 경로에 위치하는 파일이 존재하지 않습니다." << endl;
		}



		while (file.good()) //eof, bad, fail 함수가 거짓의 참을 반환할 때까지..
		{
			vector<string> row = csv_read_row(file, ',');

			if (!row[0].find("#")) //만약 csv 파일 안에 # 문자가 있을경우
			{
				continue; //그냥 건너 뛰어라
			}
			else //#문자가 없을 경우
			{
				for (int i = 0, leng = row.size(); i < leng; i++)
				{
					cout << "[" << row[i] << "]" << "\t"; //알맞게 출력


				}
				cout << endl;

				vctr.push_back(row); //결국 이차원 벡터에 저장
			}


		}
		file.close();

	}
	void writeDemo() {  //////////파일입력 :: 현재의 벡터를 기준으로 저장한다
						//ifstream은 파일을 읽게 해주는 함수로써 ifstream (파일명 or 경로)
		ofstream file(filename);

		if (file.fail())  //만약 bad() 함수가 실패 하면..
		{
			cout << "해당 경로에 위치하는 파일이 존재하지 않습니다." << endl;
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
	void vectorEdit(int num, string str1, string str2) { //// DB식 접근법 모의
														 //num번 유저, str1속성을 str2값으로 바꾼다.
														 //ex) vectorEdit(3, "ID", "김건모") -> 3번 유저 ID를 김건모로 바꾼다.
		readDemo();
		int tmpnum = 77474; // 적당히 비교를 위한 수.. 귀찮아서 대충 이렇게 제작
		for (unsigned int i = 0; i < vctr[0].size(); i++) {
			//cout << "현재 원소명 : " << vctr[0][i] << endl;
			if (vctr[0][i] == str1) {
				tmpnum = i;
			}
		}
		if (tmpnum == 77474) {
			cout << str1 << ", 그런 원소는 없다." << endl;
		}
		else {
			vctr[num][tmpnum] = str2;
		}
		writeDemo();
	}
	string vectorRead(int num, string str) {
		readDemo();
		int tmpnum = 77474;
		for (unsigned int i = 0; i < vctr[0].size(); i++) {
			//cout << "현재 원소명 : " << vctr[0][i] << endl;
			if (vctr[0][i] == str) {
				tmpnum = i;
			}
		}
		return vctr[num][tmpnum];


	}
};