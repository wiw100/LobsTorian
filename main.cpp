#include<iostream>
#include "User.h"
#include"Movie.h"
#include"Login.h"
#include"MovieService.h"
#include"Reservation.h"
#include"CSVEdit.h"

using namespace std;

int main(void) {

	//��� ���ʹ� �ϳ��� ���� ���µ�, �̸� �պ��� ���.
	//�α��ο��� ���͸� ���ְ�?
	vector<string> vtr;

	
	cout << "���´�!" << endl;

	LogIn lg;


	CSVEdit ccsv("ttest.csv");
	//csv ���� ������!
	


	//ccsv.readDemo();
	//lg.readDemo();
	
	//lg.vectorEdit(3, "ID", "�ƹ���");
	//lg.writeDemo();

	MovieService mv;

	system("pause");
}