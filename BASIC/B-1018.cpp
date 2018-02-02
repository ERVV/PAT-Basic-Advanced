#include<stdio.h>

int judge(char x, char y)
{
	int t = 0;
	if(x != y)
	{
		switch(x){
			case 'J':
			{
				if(y == 'B') t = 1;
				else t = -1;
				break;
			}
			case 'C':
			{
				if(y == 'J') t = 1;
				else t = -1;
				break;
			}
			case 'B':
			{
				if(y == 'C') t = 1;
				else t = -1;
				break;
			}
		}
	}
	return t;
}

char favor(int j, int c, int b)
{
	char tem;
	if(j>c)
	{
		if(j>b) tem = 'J';
		else tem = 'B';
	}
	else if(c>b) tem = 'C';
	else tem = 'B';
	return tem;
}

int main()
{
	int n, flag, count1 = 0, count2 = 0, count3 = 0;
	char x, y;
	int countxj = 0, countxc = 0, countxb = 0, countyj = 0, countyc = 0, countyb = 0;
	
	scanf("%d\n", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%c %c\n", &x, &y);
		flag = judge(x, y);
		if(flag == 1) 
		{
			count1++;
			switch(x)
			{
				case 'J':countxj++;break;
				case 'C':countxc++;break;
				case 'B':countxb++;break;
			}
		}
		else if(flag == -1) 
		{
			count3++;
			switch(y)
			{
				case 'J':countyj++;break;
				case 'C':countyc++;break;
				case 'B':countyb++;break;
			}
		}
		else count2++;
	}
	printf("%d %d %d\n", count1, count2, count3);
	printf("%d %d %d\n", count3, count2, count1);
	printf("%c %c", favor(countxj, countxc, countxb),
					favor(countyj, countyc, countyb));
	return 0;
}
