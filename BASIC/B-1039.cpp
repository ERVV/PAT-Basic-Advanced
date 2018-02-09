#include<stdio.h>
#include<ctype.h>

int main()
{
	int digit[10] = {0}, upper[26] = {0}, lower[26] = {0};
	char c;
	int len_sold = 0, len_want = 0;
	while((c=getchar())!='\n')
	{
		if(isdigit(c))
		{
			digit[c-'0']++;
		}
		else if(isupper(c))
		{
			upper[c-'A']++;
		}
		else if(islower(c))
		{
			lower[c-'a']++;
		}
		len_sold++;
	}
	while((c=getchar())!='\n')
	{
		if(isdigit(c))
		{
			int i = c - '0';
			if(digit[i])
			{
				digit[i]--;
				len_sold--;
			}
			else len_want++;
		}
		else if(isupper(c))
		{
			int i = c - 'A';
			if(upper[i])
			{
				upper[i]--;
				len_sold--;
			}
			else len_want++;
		}
		else if(islower(c))
		{
			int i = c-'a';
			if(lower[i])
			{
				lower[i]--;
				len_sold--;
			}
			else len_want++;
		}
	}
	if(len_want) printf("No %d", len_want);
	else printf("Yes %d", len_sold);
	return 0;
}
