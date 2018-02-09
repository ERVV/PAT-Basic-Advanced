#include<stdio.h>

typedef struct
{
	char number[15];
	int seat1, seat2;
}record;

int main()
{
	char num[15];
	int seat1, seat2;
	int n, m;
	bool flag = false;
	scanf("%d", &n);
	record stu[n+1];
	for(int i=0; i<n; i++)
	{
		scanf("%14s %d %d", num, &seat1, &seat2);
		for(int j=0; j<15; j++)
			stu[seat1].number[j] = num[j];
		stu[seat1].seat1 = seat1;
		stu[seat1].seat2 = seat2;
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int query;
		scanf("%d", &query);
		if(flag) printf("\n");
		else flag = true;
		printf("%s %d", stu[query].number, stu[query].seat2);
	}
	return 0;
}
