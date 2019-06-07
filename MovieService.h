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
		//�ϴ� �̷��� ������ ����..

		readDemo();
		movieSet();
		/*
		movie.setMovieId(1);
		movie.setMovieName("�����");
		time.push_back("5�� 29�� 15�� 30��");
		time.push_back("5�� 29�� 19�� 50��");
		time.push_back("5�� 29�� 22�� 05��");
		time.push_back("5�� 30�� 10�� 25��");
		time.push_back("6�� 1�� 11�� 30��");
		time.push_back("6�� 1�� 16�� 30��");
		movie.setMovieTime(time);
		movieList.push_back(movie);
		time.clear();
		movie.setMovieId(2);
		movie.setMovieName("������");
		time.push_back("5�� 29�� 11�� 05��");
		time.push_back("5�� 29�� 13�� 50��");
		time.push_back("5�� 30�� 10�� 20��");
		time.push_back("5�� 30�� 15�� 15��");
		time.push_back("5�� 31�� 11�� 30��");
		time.push_back("6�� 1�� 16�� 30��");
		time.push_back("6�� 1�� 22�� 30��");
		time.push_back("6�� 2�� 12�� 25��");
		movie.setMovieTime(time);
		movieList.push_back(movie);
		time.clear();
		movie.setMovieId(3);
		movie.setMovieName("�������:��������");
		time.push_back("5�� 29�� 09�� 25��");
		time.push_back("5�� 29�� 12�� 40��");
		time.push_back("5�� 29�� 18�� 15��");
		time.push_back("5�� 30�� 10�� 25��");
		time.push_back("5�� 30�� 14�� 30��");
		time.push_back("5�� 31�� 11�� 30��");
		time.push_back("5�� 31�� 16�� 45��");
		time.push_back("6�� 1�� 06�� 10��");
		time.push_back("6�� 1�� 11�� 30��");
		time.push_back("6�� 1�� 16�� 30��");
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

	//movieId�� ���� reservableTimeã���ִ� �޼���
	list<string> getMovieTimeByMovieId(int movieId) {
		list<Movie>::iterator i;
		for (i = movieList.begin(); i != movieList.end(); ++i) {
			if ((*i).getMovieId() == movieId)
				return (*i).getMovieTime();
		}
	}

	void readDemo() {
		ifstream file("movieinfo6.csv");

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

				dataV.push_back(row); //�ᱹ ������ ���Ϳ� ����
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
				movie.setMovieName("�����");
				time.push_back("5�� 29�� 15�� 30��");
				time.push_back("5�� 29�� 19�� 50��");
				time.push_back("5�� 29�� 22�� 05��");
				time.push_back("5�� 30�� 10�� 25��");
				time.push_back("6�� 1�� 11�� 30��");
				time.push_back("6�� 1�� 16�� 30��");
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