#include<stdio.h>

int callatz(int n)
{
	int x;
	if(n == 0) x = n;
	else if(n % 2) x = (3 * n + 1) / 2;
	else x = n / 2;
	return x;
}

int main(){
	int n, t;
	int a[101] = {0}, cover[101] = {0};
	bool out = false;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &t);
		a[t] = 1;
		if(!cover[t])
			while(t != 1)
			{
				t = callatz(t);
				if(t<101 && cover[t]) break;
				else if(t<101) cover[t] = 1;
			}
	}
	for(int i=100; i>1; i--)
	{
		if(a[i] && !cover[i])
		{
			if(out) printf(" ");
			else out=true;
			printf("%d", i);
		}
	}
	return 0;
}
