#include<iostream>
#include "User.h"
#include"Movie.h"
#include"Login.h"
#include"MovieService.h"
#include"Reservation.h"
#include"CSVEdit.h"

using namespace std;

int main(void) {

	//사실 벡터는 하나면 문제 없는데, 이를 손보면 어떨지.
	//로그인에서 벡터를 없애고?
	vector<string> vtr;

	
	cout << "나온다!" << endl;

	LogIn lg;


	CSVEdit ccsv("ttest.csv");
	//csv 파일 에디터!
	


	//ccsv.readDemo();
	//lg.readDemo();
	
	//lg.vectorEdit(3, "ID", "아무개");
	//lg.writeDemo();

	MovieService mv;

	system("pause");
}