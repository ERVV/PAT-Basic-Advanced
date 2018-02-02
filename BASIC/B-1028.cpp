#include<stdio.h>

typedef struct
{
	char name[10];
	int y, m, d;
}record;

int agecmp(record a, record b)
{
	int t = 0;
	if(a.y != b.y) t = a.y - b.y;
	else if(a.m != b.m) t = a.m - b.m;
	else t = a.d - b.d;
	return t;
}

int main()
{
	int n, count = 0; 
	record bir, old, young;
	record today = {"today", 2014, 9, 6},
		   theday = {"200ago", 1814, 9, 6};
	bool flag = true;
	char c;
	
	scanf("%d\n", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s %d/%d/%d", bir.name, &bir.y, &bir.m, &bir.d);
		getchar();
		
		if(agecmp(bir, today) <= 0 && agecmp(bir, theday) >= 0)
		{
			count++;
			if(flag)
			{
				old = bir;
				young = bir;
				flag = false;
			}
			else
			{
				if(agecmp(bir, old) <=0) old = bir;
				if(agecmp(bir, young) >= 0) young = bir;
			}
		}
	}
	if(count) printf("%d %s %s", count, old.name, young.name);
	else printf("%d", count);
	return 0;
}
