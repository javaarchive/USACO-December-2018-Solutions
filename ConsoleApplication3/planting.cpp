// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Note: Renamed it to planting.cpp

//#include "pch.h"
#include <iostream>
#include <fstream>
#include<map>
#include<vector>
#include <algorithm>
#include <iterator> 
std::ifstream fin("planting.in");
std::ofstream fout("planting.out");
/*
bool contains(std::vector<int> v,int x) {
	if (std::find(v.begin(), v.end(), x) != v.end()) {
		return true;
	}
	else {
		return false;
	}
}*/
bool mcontains(std::map<int, std::vector<int>> v, int x) {
	/*
	//if (std::find(v.begin(), v.end(), x) != v.end()) {
		return true;
	//}
	//else {
		return false;
	//}
	*/
	if (v.count(x) > 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	//std::map<int, std::vector<int>>::iterator itr;
	int N;
	fin >> N;
	std::cout << N;
	std::map<int, std::vector<int>> edgeList;
	int x, y;
	std::vector<int> test;
	
	for (int i = 0; i < N - 1; i ++) {
		//std::cout << "Test " << i << std::endl;
		fin >> x;
		fin >> y;
		if (mcontains(edgeList,x)) {
			edgeList.insert(std::pair<int, std::vector<int>>(x, test));
		}if (mcontains(edgeList, y)) {
			edgeList.insert(std::pair<int, std::vector<int>>(y, test));
		}
		edgeList[x].push_back(y);
		edgeList[y].push_back(x);
		//std::cout << "(" << x << "," << y << ")";
		//std::cout << "Output of begin and end: ";
		//for (auto i = test.begin(); i != test.end(); ++i)
			//std::cout << *i << " ";	
	}
	//for (std::map<int, std::vector<int>>::iterator itr = edgeList.begin(); itr != edgeList.end(); ++itr) {
	//	std::cout << "value \t" << itr->first << '\t'  << '\n';
	//	std::vector<int> path = itr->second;
	//	for (std::vector<int>::iterator i = path.begin(); i != path.end(); ++i)
	//		std::cout << itr->first << ":" << *i << ' ' << std::endl;
	//}
	//std::cin >> N;
	const int MAXSIZE = 100000;
	//int field[MAXSIZE];
	int *field = new int[N +1];
	//int colorUsedAll[MAXSIZE];
	int *colorUsedAll = new int[N ];
	int totalColorUsed = 0;
	for (std::map<int, std::vector<int>>::iterator itr = edgeList.begin(); itr != edgeList.end(); ++itr) {
		//int colorUsed[MAXSIZE];
		int *colorUsed = new int[N ];
		for (int sub : edgeList[itr ->first]) {
			//std::cout << "Parent 1";
			int f2 = field[sub];

			if (f2 > 0)
				colorUsed[f2 - 1] = 1;
			for (int sub2 : edgeList[sub]) {
				//std::cout << "Child 1";
				int f3 = field[sub2];
				if (f3 > 0)
					colorUsed[f3 - 1] = 1;

			}
		}
		int addflag = 1;
		for (int j = 0; j < totalColorUsed; j++) {

			//std::cout << "Child 2";
			if (colorUsed[j] == 0) {
				field[itr->first] = j + 1;
				colorUsedAll[j] = 1;
				addflag = 0;
				break;
			}
			

		}

		if (addflag == 1) {
			field[itr->first] = totalColorUsed + 1;
			totalColorUsed++;
			std::cout << "Added " << itr->first;
		}
		delete[] colorUsed;
		
	}
	delete[] field, colorUsedAll;
	fout << totalColorUsed;
	


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
