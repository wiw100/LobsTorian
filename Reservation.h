#pragma once
#include <iostream>
#include <string>
#include <list>
#include"Movie.h"
#include"Login.h"
#include"User.h"

using namespace std;

//�ӽ÷� ���� Movie class

/*
class Movie {
private:
	list<string> reserve;
	string movieName;

public:
	string getMovieName(int movieID) {
		return movieName;
	}
};
*/
class Reservation :Movie {
private:
	string userID; //���� ���̵�
	string reserverName; //�����ڸ�
	string movieName; //���࿵ȭ ����
	string movieTime; //���࿵ȭ �Ͻ�
	list<string> movieSeat; //������ ��ȭ�¼��� ����Ʈ�� ����.

	int adultNum = 0, childNum = 0; //���ΰ� ����� �ο��� ���� ����
	int price = 0; //�����ݾ� ����

public:
	//�������� ����
	void setUserID(string ID) {
		this->userID = ID;
	}
	string getUserID() {
		return this->userID;
	}
	void setReserverName(string name) {
		this->reserverName = name;
	}
	string getReserverName() {
		return this->reserverName;
	}
	void setmovieName(string movieName) {
		this->movieName = movieName;
	}
	string getmovieName() {
		return this->movieName;
	}
	void setmovieTime(string movieTime) {
		this->movieTime = movieTime;
	}
	string getmovieTime() {
		return this->movieTime;
	}

	//������ �ο��� ����
	void setAdultNum(int adultNum) {
		this->adultNum = adultNum;
	}
	void setChildNum(int childNum) {
		this->childNum = childNum;
	}
	int getAdultNum() {
		return this->adultNum;
	}
	int getChildNum() {
		return this->childNum;
	}
	//���� ����
	void plusAdult() {
		int adult = getAdultNum();
		adult++;
		setAdultNum(adult);
	}
	void minusAdult() {
		int adult = getAdultNum();
		if (adult>0) {
			adult--;
			setAdultNum(adult);
		}
		else {
			adult = 0;
			setAdultNum(adult);
			cout << "���� ������ ���� 1 �̸��Դϴ�." << endl;
		}
	}
	//��� ����
	void plusChild() {
		int child = getChildNum();
		child++;
		setChildNum(child);
	}
	void minusChild() {
		int child = getChildNum();
		if (child>0) {
			child--;
			setChildNum(child);
		}
		else {
			child = 0;
			setChildNum(child);
			cout << "��� ������ ���� 1 �̸��Դϴ�." << endl;
		}
	}
	//�����ݾ� ��ȯ
	int printPrice() {
		this->price = getAdultNum() * 10000 + getChildNum() * 8000;
		return this->price;
	}
	//�¼��� ������ �� ���
	void selectMovieSeat(string seatName) {
		movieSeat.push_back(seatName);
	}
	//�¼��� ����� �� ���
	void cancelMovieSeat(string seatName) {
		movieSeat.remove(seatName);
	}
	/*
	Movie class ��� �ʿ�κ�
	����Ʈ ��ºκ��� GUI���� ¥�� �Ǵ� ������?
	*/
	//��ȭ����Ʈ ���
	void showMovieList() {
		/*
		list<Movie> movieList = Movie::getmovieList();
		list<Movie>::iterator i;

		for(i = movieList.begin(); i!=movieList.end(); i++) {
		//cout<< *i << endl;
		}
		*/
	}
	void selectMovie(int movieID) {
		string movieName;

		showMovieList();
		cin >> movieName;
		setmovieName(movieName);
	}
	void selectMovieTime(int movieID) {
		string movieTime;

		cin >> movieTime;
		setmovieTime(movieTime);
	}
	//��ȭ���ý� �ð� ���
	void showMovieTime(int movieID) {
		/*
		list<string> movieTime = getMovieTime(movieID);
		list<string>::iterator i;

		for(i = movieTime.begin(); i!=movieTime.end(); i++) {
		cout << *i << endl;
		}
		*/
	}
	void selectMovieTime(string movieTime) {
		this->setmovieTime(movieTime);
	}
	//�������� ������Ʈ
	//Movie class�� User class�� ��ӹ޾� ���� ������Ʈ
	void updateReservation() {

	}
};
