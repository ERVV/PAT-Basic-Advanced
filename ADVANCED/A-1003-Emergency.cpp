#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 502;
const int INF = 2000000000;

int N, M;
int G[MAX][MAX], weight[MAX];
int d[MAX], w[MAX], num_path[MAX];
bool visit[MAX];

void dijkstra(int st)
{
	for(int i=0; i<N; i++)
	{
		d[i] = INF;
		w[i] = 0;
		num_path[i] = 0;
		visit[i] = false;
	}
	d[st] = 0;
	visit[st] = true;
	w[st] = weight[st];
	num_path[st] = 1;
	int new_p = st;
	for(int i=0; i<N; i++)
	{
		int min = INF;
		for(int j=0; j<N; j++)
		{
			if(visit[j] || d[j]>=min) continue;
			min = d[j];
			new_p = j;
		}
		visit[new_p] = true;
		
		for(int j=0; j<N; j++)
		{
			if(visit[j]) continue;
			if(d[j] > d[new_p]+G[new_p][j])
			{
				d[j] = d[new_p] + G[new_p][j];
				num_path[j] = num_path[new_p];
				w[j] = w[new_p] + weight[j];
			}
			else if(d[j] == d[new_p]+G[new_p][j])
			{
				w[j] = max(w[j], weight[j]+w[new_p]);
				num_path[j] += num_path[new_p];
			}
		}
	}
	return;
}

int main()
{
	int start, end;
	scanf("%d%d%d%d", &N, &M, &start, &end);
	for(int u=0; u<N; u++)
		for(int v=0; v<N; v++)
			G[u][v] = INF;
	for(int i=0; i<N; i++)
		scanf("%d", &weight[i]);
	for(int i=0; i<M; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	dijkstra(start);
	printf("%d %d", num_path[end], w[end]);
	return 0;
}
