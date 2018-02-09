#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int n , count = 0, max = 0, min = 1000000001;
	int pivot[100000];
	int data[100000];
	bool lmax[100000] = {false}, rmin[100000] = {false};
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &data[i]);
	for(int i=0; i<n; i++)
	{
		if(data[i] > max)
		{
			max = data[i];
			lmax[i] = true;
		}
		if(data[n-1-i] < min)
		{
			min = data[n-1-i];
			rmin[n-1-i] = true;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(lmax[i] && rmin[i])
		{
			pivot[count++] = data[i];
		}
	}
	sort(pivot, pivot+count);
	printf("%d\n", count);
	for(int i=0; i<count; i++)
	{
		if(i) printf(" ");
		printf("%d", pivot[i]);
	}
	if(!count) printf("\n");
	return 0;
}
