#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct
{
	int pop_time, end_time;
	queue<int> Q;
}Node;

int main()
{
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	vector<Node> windows(N);
	vector<int> time(K+1), result(K+1);
	for(int i=0; i<K; i++)
	{
		scanf("%d", &time[i+1]);
	}
	int customer_index = 1;
	vector<bool> sorry(K+1, false);
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(customer_index>K) break;
			windows[j].Q.push(customer_index);
			if(windows[j].end_time >= 540)
				sorry[customer_index] = true;
			windows[j].end_time += time[customer_index];
			result[customer_index] = windows[j].end_time;
			customer_index++;
			if(!i) windows[j].pop_time = windows[j].end_time;
		}
	}
	while(customer_index <= K)
	{
		int min_wid=0;
		for(int i=0; i<N; i++)
		{
			if(windows[i].pop_time >= windows[min_wid].pop_time) continue;
			min_wid = i;
		}
		windows[min_wid].Q.pop();
		int next = windows[min_wid].Q.front();
		windows[min_wid].pop_time = result[next];
		windows[min_wid].Q.push(customer_index);
		if(windows[min_wid].end_time >= 540)
			sorry[customer_index] = true;
		windows[min_wid].end_time += time[customer_index];
		result[customer_index] = windows[min_wid].end_time;
		customer_index++;
	}
	for(int i=0; i<Q; i++)
	{
		int query;
		scanf("%d", &query);
		if(sorry[query])
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", result[query]/60+8, result[query]%60);
	}
	return 0;
}
