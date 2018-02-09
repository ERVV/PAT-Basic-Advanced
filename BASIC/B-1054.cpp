#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define fal 1001

double trans(char s[])
{
	int dot = 0, sign = 0;
	int len = strlen(s);
	double data = 0;
	for(int i=0; i<len; i++){
		if(!i && s[i] == '-')
		{
			sign = 1;
			continue;
		}
		if(isalpha(s[i])) return fal;
		if(s[i] == '.')
		{
			if(dot) return fal;
			dot = 1;
			if(len-i > 3) return fal;
			continue;
		}
		data = data * 10 + s[i] - '0';
		if(dot) dot++;
	}
	for(int i=1; i<dot; i++)
	{
		data /= 10;
	}
	if(sign)
		data *= -1;
	return data;
}

int main()
{
	int n, cnt = 0;
	char s[100];
	double sum = 0, ave, data;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s", s);
		data = trans(s);
		if(data>=-1000 && data<=1000)
		{
			cnt++;
			sum += data;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", s);
		}
	}
	if(cnt==1)
	{
		printf("The average of 1 number is %.2lf\n", sum);
	}
	else if(!cnt)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else
	{
		ave = sum / cnt;
		printf("The average of %d numbers is %.2lf\n", cnt, ave);
	}
	return 0;
}
