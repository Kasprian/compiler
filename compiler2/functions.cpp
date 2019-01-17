#include "functions.h"
#include <iostream>
#include "parser.tab.h" 

using namespace std;

long long int myfind(vector<variable> variables, string s){
	for(long long int i = 0; i < variables.size(); i++){
		if(variables[i].name == s)
			return i;
	}
	return -1;
}

/*long long myfindTable(vector<variable> variables, string s, string index){
	for(long long i = 0; i < variables.size(); i++){
		if(variables[i].name == s && variables[i].index== atoll(index.c_str());)
			return i;
	}
	return -1;
}*/

bool isNumber(string line){
	long long int n = line.length();
    for(long long int i = 0; i < n; i++)
    	if(!isdigit(line[i]))
    		return false;
    return true;
}
string toString(long long int value){
	stringstream ss;
	ss << value;
	string str = ss.str();
	return str;
}
