#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int judge(char *s)
{
	int Ppos = -1, Tpos = -1;
	int preA = 0, betA = 0, postA = 0;
	int countA = 0;
	
	bool find = true;
	int len = strlen(s);
	
	for(int i=0; i<len && find; i++)
	{
		switch(s[i])
		{
			case 'P':
			{
				if(Ppos==-1) Ppos = i;
				else find = false;
				break;
			}
			case 'T':
			{
				if(Tpos==-1) Tpos = i;
				else find = false;
				break;
			}
			case 'A': countA++; break;
			default: find = false; break;
		}
	}
	if(find && countA>0 && Ppos!=-1 && Tpos!=-1 && Ppos < Tpos-1)
	{
		preA = Ppos;
		betA = Tpos - Ppos - 1;
		postA = len - Tpos - 1;
		if(postA !=  preA * betA)
			find = false;
	}else find = false;
	return find;
}

int main(){
	char s[10][101];
	int n;	
	scanf("%d", &n);
	for(int i=0;i<n;i++) 
		scanf("%s", s[i]);

	for(int i=0;i<n;i++)
	{
		if(judge(s[i])) 
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
} 
