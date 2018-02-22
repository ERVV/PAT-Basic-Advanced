#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

typedef struct TREE
{
	bool isroot;
	int lChildID, rChildID;
	int id;
}Tree;

int string_to_int(string s)
{
	int ret = 0;
	for(int i=0;i<s.length();i++)
	{
		ret = ret * 10 + s[i]-'0';
	}
	return ret;
}

int main()
{
	int n, root=0, last=0;
	bool flag = true;
	scanf("%d", &n);
	Tree *p_tree = new Tree[n];
	for(int i=0; i<n; i++)
	{
		p_tree[i].isroot = true;
		p_tree[i].lChildID = p_tree[i].rChildID = -1;
		p_tree[i].id = -1;
	}
	for (int i=0; i<n; i++)
	{
		string first, second;
		cin >> first >> second;
		int child;
		if(first!="-") 
		{
			child = string_to_int(first);
			p_tree[child].isroot = false;
			p_tree[i].lChildID = child;
		}
		if(second!="-") 
		{
			child = string_to_int(second);
			p_tree[child].isroot = false;
			p_tree[i].rChildID = child;
		}
	}
	for(int i=0;i<n;i++) if(p_tree[i].isroot) root = i;
	
	queue<int> Q;
	Q.push(root);
	int count = 1;
	while(!Q.empty())
	{
		int p = Q.front();
		if(p_tree[p].lChildID!=-1) Q.push(p_tree[p].lChildID);
		if(p_tree[p].rChildID!=-1) Q.push(p_tree[p].rChildID);
		p_tree[p].id = count++;
		last = p;
		Q.pop();
	}
	for(int i=0; i<n; i++)
	{
		if(p_tree[i].lChildID!=-1)
			if(p_tree[p_tree[i].lChildID].id/2!=p_tree[i].id) 
				flag = false;
		if(p_tree[i].rChildID!=-1)
			if((p_tree[p_tree[i].rChildID].id-1)/2!=p_tree[i].id) 
				flag = false;
	}
	if(flag) printf("YES %d", last);
	else printf("NO %d", root);
	return 0;
}
