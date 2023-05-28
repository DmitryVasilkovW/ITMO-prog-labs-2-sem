#ifndef UNTITLED12_CUBE_H
#define UNTITLED12_CUBE_H
#include<iostream>
#include<fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include<vector>

enum Facet
{
	Top = 0,
	Bottom = 1,
	Front = 2,
	Back = 3,
	Left = 4,
	Right = 5
};


class Cube
{
	char cube[6][3][3];
	void turnMatrix(int facet, bool cw);
	char colors[6] = { 'R', 'B', 'Y', 'O', 'G', 'W' };
	std::map<std::set<char>, int> centerCubes = { {{'R','O'}, 0}, {{'B','G'}, 0}, {{'Y','W'}, 0} };

	std::map<std::set<char>, int> middleCubes = { {{'R','B'}, 0}, {{'B','Y'}, 0}, {{'Y','O'}, 0},
	                                              {{'O','G'}, 0}, {{'G','W'}, 0}, {{'W','R'}, 0},
	                                              {{'R','Y'}, 0}, {{'B','O'}, 0}, {{'Y','G'}, 0},
	                                              {{'O','W'}, 0}, {{'G','R'}, 0}, {{'B','W'}, 0}
	};

	std::map<std::set<char>, int> cornerCubes = { {{'W','G','O'}, 0}, {{'G','O','Y'}, 0},
	                                              {{'O','Y','B'}, 0}, {{'Y','B','R'}, 0},
	                                              {{'B','R','W'}, 0}, {{'R','W','G'}, 0},
	                                              {{'W','O','B'}, 0}, {{'G','Y','R'}, 0}
	};
public:
	Cube();
	friend std::ostream& operator<<(std::ostream& out, Cube& cube);
	void LoadFromFile(std::string filename);
	void F(bool cw = true);
	void B(bool cw = true);
	void L(bool cw = true);
	void R(bool cw = true);
	void U(bool cw = true);
	void D(bool cw = true);
	void Mixing();
	std::vector<std::string> cubeSolve();
	bool checkCornerCubes();
	bool checkState();
	void printt();
	void getCross();
	bool checkCross();
	bool checkSecondLayer();
	bool checkCentreCubes();
	bool checkBottomCross();
	bool checkSideCubesBottomLayer();
	bool checkCornerCubesBottomLayer();
	bool checkThirdLayer();
	bool checkLastLayer();
	void getSecondLayer();
	void getCentreCubes();
	void getCornerCubes();
	void getBottonCross();
	void getSideCubesBottomLayer();
	void getCornerCubesBottomLayer();
	void getThirdLayer();
	void input_Mixing();
	std::vector<std::string> mass;
};

#endif //UNTITLED12_CUBE_H
