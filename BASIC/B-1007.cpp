#include<stdio.h>
#include<iostream>
using namespace std;

bool isprime(int x)
{
	bool flag = true;
	if(x == 2) flag = true;
	else if(x%2==1)
	{
		for(int i=3; i*i<=x;i+=2)
		{
			if(x%i==0)
			{
				flag = false;
				break;
			}
		}
	}else
	{
		flag = false;
	}
	return flag;
}

int main()
{
	int n, count = 0;
	scanf("%d", &n);
	int pre = 3;
	for(int i=pre; i<=n; i++)
	{
		if(isprime(i))
		{
			if(i-pre==2) count++;
			pre = i;
		}
	}
	printf("%d", count);
}
