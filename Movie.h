#pragma once
#include<iostream>
#include<list>

using namespace std;

class Movie {
private:
	int movieId;
	string movieName;
	list<string> reservableMovieTime;
	//list<int> index;//ÁÂ¼® ÆÄÀÏ Çà ÀÎµ¦½º

public:
	int getMovieId() {
		return movieId;
	}
	string getMovieName() {
		return movieName;
	}
	list<string> getMovieTime() {
		return reservableMovieTime;
	}

	void setMovieId(int movieID) {
		movieId = movieID;
	}
	void setMovieName(string movieN) {
		movieName = movieN;
	}
	void setMovieTime(list<string> movieTime) {
		reservableMovieTime = movieTime;
	}

};