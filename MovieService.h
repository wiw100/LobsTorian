#pragma once
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Movie.h"

using namespace std;

class MovieService {
private:
	list<Movie> movieList;

	vector<vector<string>> dataV;
	static vector<string> csv_read_row(ifstream &file, char delimiter) {
		stringstream ss;
		bool inquotes = false;
		vector<string> row;

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

public:
	MovieService() {
		//일단 이렇게 데이터 세팅..

		readDemo();
		movieSet();
		/*
		movie.setMovieId(1);
		movie.setMovieName("기생충");
		time.push_back("5월 29일 15시 30분");
		time.push_back("5월 29일 19시 50분");
		time.push_back("5월 29일 22시 05분");
		time.push_back("5월 30일 10시 25분");
		time.push_back("6월 1일 11시 30분");
		time.push_back("6월 1일 16시 30분");
		movie.setMovieTime(time);
		movieList.push_back(movie);
		time.clear();
		movie.setMovieId(2);
		movie.setMovieName("고질라");
		time.push_back("5월 29일 11시 05분");
		time.push_back("5월 29일 13시 50분");
		time.push_back("5월 30일 10시 20분");
		time.push_back("5월 30일 15시 15분");
		time.push_back("5월 31일 11시 30분");
		time.push_back("6월 1일 16시 30분");
		time.push_back("6월 1일 22시 30분");
		time.push_back("6월 2일 12시 25분");
		movie.setMovieTime(time);
		movieList.push_back(movie);
		time.clear();
		movie.setMovieId(3);
		movie.setMovieName("엔드게임:가망없음");
		time.push_back("5월 29일 09시 25분");
		time.push_back("5월 29일 12시 40분");
		time.push_back("5월 29일 18시 15분");
		time.push_back("5월 30일 10시 25분");
		time.push_back("5월 30일 14시 30분");
		time.push_back("5월 31일 11시 30분");
		time.push_back("5월 31일 16시 45분");
		time.push_back("6월 1일 06시 10분");
		time.push_back("6월 1일 11시 30분");
		time.push_back("6월 1일 16시 30분");
		movie.setMovieTime(time);
		movieList.push_back(movie);
		time.clear();
		*/
	}

	list<Movie> getMovieList() {
		return movieList;
	}
	void setMovieList(list<Movie> movieL) {
		movieList = movieL;
	}
	vector<vector<string>> getDataV() {
		return dataV;
	}

	//movieId에 따라 reservableTime찾아주는 메서드
	list<string> getMovieTimeByMovieId(int movieId) {
		list<Movie>::iterator i;
		for (i = movieList.begin(); i != movieList.end(); ++i) {
			if ((*i).getMovieId() == movieId)
				return (*i).getMovieTime();
		}
	}

	void readDemo() {
		ifstream file("movieinfo6.csv");

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

				dataV.push_back(row); //결국 이차원 벡터에 저장
			}


		}
		file.close();

	}
	/*
	string vectorRead(int num, string str) {
		int tmpnum = 77474;
		for (int i = 0; i < dataV[0].size(); i++) {
			if (dataV[0][i] == str) {
				tmpnum = i;
			}
		}
		return dataV[num][tmpnum];
	}
	*/
	void movieSet() {
		Movie movie;
		list<string> time;
		int i = 0;
		/*		movie.setMovieId(1);
				movie.setMovieName("기생충");
				time.push_back("5월 29일 15시 30분");
				time.push_back("5월 29일 19시 50분");
				time.push_back("5월 29일 22시 05분");
				time.push_back("5월 30일 10시 25분");
				time.push_back("6월 1일 11시 30분");
				time.push_back("6월 1일 16시 30분");
				movie.setMovieTime(time);
				movieList.push_back(movie);
				time.clear();*/
		for (vector<string> vec : dataV) {
			for (string str : vec) {
				if (i == 0) {
					movie.setMovieId(atoi(str.c_str()));
				}
				else if (i == 1) {
					movie.setMovieName(str);
				}
				else
					time.push_back(str);
				i++;
			}
			movie.setMovieTime(time);
			movieList.push_back(movie);
			time.clear();
			i = 0;
		}
	}
};