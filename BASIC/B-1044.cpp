#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char lower[13][10] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	char higher[13][10] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	char number[100][10];
	int n; 
	scanf("%d\n", &n);
	for(int i=0; i<n; i++) gets(number[i]);
	
	for(int j=0; j<n; j++)
	{
		if(j) printf("\n");
		int sum = 0;
		if(isdigit(number[j][0]))
		{
			for(int i=0; number[j][i]!='\0'; i++)	
				sum = 10 * sum + number[j][i] - '0';
			int h = sum / 13;
			int l = sum % 13;
			if(h)
			{
				printf("%s", higher[h]);
				if(l) printf(" %s", lower[l]);
			}
			else printf("%s", lower[l]);
		}
		else
		{
			for(int i=0; i<13; i++)
			{
				if(strstr(number[j], higher[i]))
				{
					sum += 13 * i;
					break;
				}
			}
			for(int i=0; i<13; i++)
			{
				if(strstr(number[j], lower[i]))
				{
					sum += i;
					break;
				}
			}
			printf("%d", sum);
		}
	}
	return 0;
} 

