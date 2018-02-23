#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int>* CITY;
int VISIT[1001];

void DFS(int id)
{
	VISIT[id] = 1;
	for(int i=0; i<CITY[id].size();i++)
	{
		if(VISIT[CITY[id][i]]) continue;
		DFS(CITY[id][i]);
	}
	return;
}

int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	CITY = new vector<int>[N+1];
	for(int i=0; i<M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		CITY[a].push_back(b);
		CITY[b].push_back(a);
	}
	for(int i=0; i<K; i++)
	{
		int lost;
		scanf("%d", &lost);
		for(int j=1; j<=N; j++)
			VISIT[j] = 0;
		VISIT[lost] = 1;
		int count = 0;
		for(int j=1; j<=N; j++)
		{
			if(VISIT[j]) continue;
			DFS(j);
			count++;
		}
		printf("%d\n", count-1);
	}
	return 0;
}
