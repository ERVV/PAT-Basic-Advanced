#include<stdio.h>
#include<ctype.h>

int main()
{
	bool alpha[26]={false}, digit[10]={false};
	bool space=false, comma=false, dot=false, sub=false, shift=false;
	char c;
	bool flag;
	
	while((c=getchar()) != '\n')
	{
		if(isdigit(c)) digit[c-'0'] = true;
		else if(isupper(c)) alpha[c-'A'] = true;
		else
			switch(c)
			{
				case '_': space = true; break;
				case ',': comma = true; break;
				case '.': dot = true; break;
				case '-': sub = true; break;
				case '+': shift = true; break;
			}
	}
	while((c=getchar())!='\n')
	{
		flag = false;
		if(isdigit(c) && !digit[c-'0']) flag = true;
		else if(isupper(c) && (!shift) && (!alpha[c-'A']))
				flag = true;
		else if(islower(c) && (!alpha[c-'a']))
				flag = true;	
		else
			switch(c)
			{
				case '_': if(!space) putchar('_'); break;
				case ',': if(!comma) printf(","); break;
				case '.': if(!dot) printf("."); break;
				case '-': if(!sub) printf("-"); break;
			}
		if(flag) printf("%c", c);  
	}
	return 0;
}
