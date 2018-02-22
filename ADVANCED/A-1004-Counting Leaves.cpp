#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;

typedef struct node
{
	int lvl, child_cnt;
	vector<int> child;
}Node;

int main()
{
	int N, M, max_lvl;
	scanf("%d%d", &N, &M);
	int* ans = new int[102];
	memset(ans, 0, sizeof(int)*102);
	Node* fam = new Node[N];
	memset(fam, 0, sizeof(Node)*N);
	for(int i=0; i<M; i++)
	{
		int id, cnt;
		scanf("%d", &id);
		scanf("%d", &cnt);
		fam[id-1].child_cnt = cnt;
		while(cnt--)
		{
			int child_id;
			scanf("%d", &child_id);
			fam[id-1].child.push_back(child_id);
		}
	}
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	Q.push(1);
	fam[0].lvl = 0;
	while(!Q.empty())
	{
		int parent = Q.front();
		Q.pop();
		if(!fam[parent-1].child_cnt)
		{
			max_lvl = fam[parent-1].lvl;
			ans[max_lvl]++;
			continue;
		}
		for(int i=0; i<fam[parent-1].child_cnt; i++)
		{
			int child = fam[parent-1].child[i];
			fam[child-1].lvl = fam[parent-1].lvl + 1;
			Q.push(child);
		}
	}
	for(int i=0; i<=max_lvl; i++)
	{
		if(i) printf(" ");
		printf("%d", ans[i]);
	}
	delete[] ans;
	delete[] fam;
	return 0;
}
