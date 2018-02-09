#include<stdio.h>
#include<math.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, m, n;
	int *data, **square;
	
	scanf("%d", &N);
	m = sqrt(N);
	n = N / m;
	while(m*n!=N || m < n)
	{
		m++;
		n = N / m;
	}
	data = (int *)malloc(N * sizeof(int));
	square = (int **)malloc(m * sizeof(int *));
	for(int i=0; i<m; i++) square[i] = (int *)malloc(n * sizeof(int));
	
	for(int i=0; i<N; i++) scanf("%d", &data[i]);
	sort(data, data+N);
	
	int num=N;
	int up = -1, down = m, left = -1, right = n;
	int flag = 0;
	while(num)
	{
		for(int i=up+1,j=left+1; j<right && num; j++) 
		{
			square[i][j] = data[--num];
			flag = 1;
		}
		if(flag) {up++;flag=0;}
		for(int i=up+1,j=right-1; i<down && num; i++) 
		{
			flag = 1;
			square[i][j] = data[--num];
		}
		if(flag) {right--;flag=0;}
		for(int i=down-1,j=right-1; j>left && num; j--)
		{
			flag = 1;
			square[i][j] = data[--num];
		}
		if(flag) {down--;flag=0;}
		for(int i=down-1,j=left+1; i>up && num; i--) 
		{
			flag = 1;
			square[i][j] = data[--num];
		}
		if(flag){left++;flag=0;}
	}

	for(int i=0; i<m; i++)
	{
		if(i) printf("\n");
		for(int j=0; j<n; j++) 
		{
			if(j) printf(" ");
			printf("%d", square[i][j]);
		}
	}
	return 0;
} 
