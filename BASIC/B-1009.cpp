#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<string> sentence;
	string s;
	do
	{
		cin >> s;
		sentence.push_back(s);
	}while(cin.peek()!='\n');
	int size = sentence.size();
	for(int i=size-1; i>=0; i--)
	{
		cout << sentence[i];
		if(i>0) cout << ' ';
	}
	return 0;
}
