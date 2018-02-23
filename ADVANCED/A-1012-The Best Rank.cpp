#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct
{
	int ID, grade[4];
}Node;

Node stu[2005];
int rank_each[1000000][4] = {0};
static int flag;

int cmp(const Node a, const Node b)
{
	return a.grade[flag] > b.grade[flag];
}

int main()
{
	int a, c, m, e;
	int N, M;
	char course[4] = {'A', 'C', 'M', 'E'};
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &stu[i].ID);
		scanf("%d%d%d", &c, &m, &e);
		a = (c + m + e) / 3;
		stu[i].grade[0] = a;
		stu[i].grade[1] = c;
		stu[i].grade[2] = m;
		stu[i].grade[3] = e;
	}
	for(flag=0; flag<4; flag++)
	{
		sort(stu, stu+N, cmp);
		rank_each[stu[0].ID][flag] = 1;
		for(int i=1; i<N; i++)
			if(stu[i-1].grade[flag] != stu[i].grade[flag])
				rank_each[stu[i].ID][flag] = i+1;
			else 
				rank_each[stu[i].ID][flag] = rank_each[stu[i-1].ID][flag];
	}
	int query;
	while(M--)
	{
		scanf("%d", &query);
		if(!rank_each[query][0])
			printf("N/A\n");
		else 
		{
			int best = 0;
			for(int i=1; i<4; i++)
				if(rank_each[query][i] < rank_each[query][best])
					best = i;
			printf("%d %c\n", rank_each[query][best], course[best]);
		}
	}
	return 0;
}
