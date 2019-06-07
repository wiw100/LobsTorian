#pragma once
#include <iostream>
#include <string>
#include <list>
#include"Movie.h"
#include"Login.h"
#include"User.h"

using namespace std;

//임시로 넣은 Movie class

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
	string userID; //유저 아이디
	string reserverName; //예약자명
	string movieName; //예약영화 제목
	string movieTime; //예약영화 일시
	list<string> movieSeat; //선택한 영화좌석은 리스트로 관리.

	int adultNum = 0, childNum = 0; //성인과 어린이의 인원수 저장 변수
	int price = 0; //결제금액 저장

public:
	//예약정보 세팅
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

	//관람객 인원수 세팅
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
	//성인 세팅
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
			cout << "성인 관람객 수가 1 미만입니다." << endl;
		}
	}
	//어린이 세팅
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
			cout << "어린이 관람객 수가 1 미만입니다." << endl;
		}
	}
	//결제금액 반환
	int printPrice() {
		this->price = getAdultNum() * 10000 + getChildNum() * 8000;
		return this->price;
	}
	//좌석을 예약할 때 사용
	void selectMovieSeat(string seatName) {
		movieSeat.push_back(seatName);
	}
	//좌석을 취소할 때 사용
	void cancelMovieSeat(string seatName) {
		movieSeat.remove(seatName);
	}
	/*
	Movie class 상속 필요부분
	리스트 출력부분은 GUI에서 짜면 되는 것인지?
	*/
	//영화리스트 출력
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
	//영화선택시 시간 출력
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
	//예매정보 업데이트
	//Movie class와 User class를 상속받아 정보 업데이트
	void updateReservation() {

	}
};
