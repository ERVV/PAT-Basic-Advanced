#include <stdio.h>
#include <vector>

using namespace std;

const int INF = 999999999;
int N;
vector<int> u_path_len, u_path_time;
int ans_dis=0, ans_time=0;

void dijkstra(vector<vector<int> > &map, vector< vector<int> > &pre, int start)
{
	vector<int> visited(N, false);
	vector<int> dis(map[start]);
	
	while(true)
	{
		int min_d = INF, min_index = -1;
		for(int i=0; i<N; i++)
		{
			if(visited[i] || min_d <= dis[i]) continue;
			min_index = i;
			min_d = dis[i];
		}
		if(min_index == -1) break;
		visited[min_index] = true;
		for(int i=0; i<N; i++)
		{
			if(visited[i]) continue;
			if(dis[i] > dis[min_index]+map[min_index][i])
			{
				dis[i] = dis[min_index]+map[min_index][i];
				pre[i].clear();
				pre[i].push_back(min_index);
			}
			else if(dis[i] == dis[min_index]+map[min_index][i])
			{
				pre[i].push_back(min_index);
			}
		}
	}
	return;
}

void DFS_len_fast(vector<vector<int> > &pres, int start, vector<int> &tmp_path,
				  int cur, int &min, int time, int dis,
				  vector<vector<int> > &map_time, vector<vector<int> > &map_len)
{
	if(start==cur && time<min)
	{
		min = time;
		u_path_len = tmp_path;
		ans_dis = dis;
		return;
	}
	for(int i=0; i<pres[cur].size(); i++)
	{
		int pre = pres[cur][i];
		tmp_path.push_back(pre);
		DFS_len_fast(pres, start, tmp_path,
					 pre, min, time+map_time[pre][cur], dis+map_len[pre][cur],
					 map_time, map_len);
		tmp_path.pop_back();
	}
	return;
}

void DFS_time_short(vector<vector<int> > &pres, int start, vector<int> &tmp_path,
				    int cur, int &min, int time, int cnt,
				    vector<vector<int> > &map_time, vector<vector<int> > &map_len)
{
	if(start==cur && cnt<min)
	{
		min = cnt;
		u_path_time = tmp_path;
		ans_time = time;
		return;
	}
	for(int i=0; i<pres[cur].size(); i++)
	{
		int pre = pres[cur][i];
		tmp_path.push_back(pre);
		DFS_time_short(pres, start, tmp_path,
					   pre, min, time+map_time[pre][cur], cnt+1,
					   map_time, map_len);
		tmp_path.pop_back();
	}
	return;
}

int main()
{
	int M, start, end;
	scanf("%d%d", &N, &M);
	vector<vector<int> > map_len(N, vector<int>(N, INF));
	vector<vector<int> > map_time(N, vector<int>(N, INF));
	for(int i=0; i<N; i++)
	{
		map_len[i][i] = map_time[i][i] = 0;
	}
	for(int i=0; i<M; i++)
	{
		int u, v, flag, len, time;
		scanf("%d%d%d%d%d", &u, &v, &flag, &len, &time);
		map_len[u][v] = len;
		map_time[u][v] = time;
		if(!flag)
		{
			map_len[v][u] = len;
			map_time[v][u] = time;
		}
	}
	scanf("%d%d", &start, &end);

	vector<vector<int> > pres_len(N), pres_time(N);
	dijkstra(map_len, pres_len, start);
	dijkstra(map_time, pres_time, start);

	vector<int> tmp_path;
	int min = INF;
	DFS_len_fast(pres_len, start, tmp_path,
				 end, min, 0, 0,
				 map_time, map_len);
	min = INF;
	tmp_path.clear();
	DFS_time_short(pres_time, start, tmp_path,
				   end, min, 0, 0,
				   map_time, map_len);
	if(u_path_len == u_path_time)
	{
		printf("Distance = %d; Time = %d: ", ans_dis, ans_time);
		for(int i=u_path_len.size()-1; i>=0; i--)
		{
			printf("%d -> ", u_path_len[i]);
		}
		printf("%d", end);
	}
	else
	{
		printf("Distance = %d: ", ans_dis);
		for(int i=u_path_len.size()-1; i>=0; i--)
		{
			printf("%d -> ", u_path_len[i]);
		}
		printf("%d", end);
		printf("\nTime = %d: ", ans_time);
		for(int i=u_path_time.size()-1; i>=0; i--)
		{
			printf("%d -> ", u_path_time[i]);
		}
		printf("%d", end);
	}
	return 0;
}
