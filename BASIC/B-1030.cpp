#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, p, max = 1;	
	scanf("%d %d", &n, &p); 
	int *input = new int[n];
	for(int i=0; i<n; i++) scanf("%d", &input[i]);
	sort(input, input+n);
	for(int i=0; i+max<n; i++)
	{
		double t = input[i] * (float)p;
		while(input[i+max] <= t && i+max < n) max++;
	}
	printf("%d", max);
	delete input;
	return 0;
}
