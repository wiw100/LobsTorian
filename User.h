#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<istream>
#include"Movie.h"

class User {
private:
	string userID;
	string userPW;
	string userName;
	int userBirth;
	int userPoint;
	string userType;
	int userNum;
	list<Movie> movieList;

public:
	//get, set 등은 그냥 딱 이름만큼의 기능들이다.
	string getUserID() {
		return userID;
	}
	string getUserPW() {
		return userPW;
	}
	string getUserName() {
		return userName;
	}
	int getUserBirth() {
		return userBirth;
	}
	int getUserPoint() {
		return userPoint;
	}
	string getUserType() {
		return userType;
	}
	int getUserNum() {
		return userNum;
	}
	list<Movie> getMovieList() {
		return movieList;
	}
	//////////////////////////////get 부분 끝
	void setUserID(string str) {
		userID = str;
	}
	void setUserPW(string str) {
		userPW = str;
	}
	void setUserName(string str) {
		userName = str;
	}
	void setUserBirth(int num) {
		userBirth = num;
	}
	void setUserPoint(int num) {
		userPoint = num;
	}
	void setUserType(string str) {
		userType = str;
	}
	void setUserNum(int num) {
		userNum = num;
	}
	void setMovieList(list<Movie> mv) {
		movieList = mv;
	}
	///////////////////////set 부분 끝
	User(string str1, string str2) { //생성자. 일단 ID,PW만 있으면 만든다고 가정했다.
		setUserID(str1);
		setUserPW(str2);
	}
	~User();
	///예매는 다른 클래스에서 하도록 한다.

};