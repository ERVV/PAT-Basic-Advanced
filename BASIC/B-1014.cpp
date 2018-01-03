#include<stdio.h>
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main(){
	string s[4];
	char day, hour;
	int minute;
	
	for(int i=0; i<4; i++)
		cin >> s[i];
	
	int p = 0;
	for(p=0; p<s[0].length() && p<s[1].length(); p++)
	{
		if(s[0][p] == s[1][p] && s[1][p]>='A'&&s[1][p]<='G') 
		{
			day = s[1][p];
			break;
		}
	}
	
	for(++p; s[0][p]!='\0' && s[1][p]!='\0'; p++)
	{
		if(s[0][p]==s[1][p]) 
		{
			if(isdigit(s[1][p]))
			{
				hour = s[1][p] - '0';
				break;
			}else if(s[1][p]>='A'&&s[1][p]<='N')
			{
				hour = s[1][p] - 'A' + 10;
				break;
			}
		}
	}
	for(int i=0; i<s[2].length() && i<s[3].length(); i++){
		if(s[2][i] == s[3][i] && isalpha(s[2][i]))
		{
			minute = i;
			break;
		}
	}
	
	string weekdays[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	cout << weekdays[day-'A'];
	printf(" %02d:%02d", hour, minute);

	return 0;
}
