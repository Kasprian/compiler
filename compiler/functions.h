#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>


using namespace std;

struct variable{
	string name;
	bool initialized;
	bool table;
	long long int beginIndex;
	long long int endIndex;
	long long int memBeginIndex;
	long long int memEndIndex;
};

long long int myfind(vector<variable> variables, string s);
bool isNumber(string line);
string toString(long long int value);