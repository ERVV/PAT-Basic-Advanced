#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	float unit_price, stock, total_price;
}Info;

int cmp(const Info &a, const Info &b)
{
    if(a.unit_price > b.unit_price) return 1;
    else return 0;
}

int main()
{
	int n, max_need; 
	float total_price = 0;
	
	scanf("%d %d", &n, &max_need);
	Info *mooncake = new Info[n];
	for(int i=0; i<n; i++) scanf("%f", &mooncake[i].stock);
	for(int i=0; i<n; i++) 
	{
		scanf("%f", &mooncake[i].total_price);
		mooncake[i].unit_price = mooncake[i].total_price / mooncake[i].stock;
	}
	sort(mooncake, mooncake+n, cmp);
	//qsort(mc, n, sizeof(mc[0]), cmp);
	
	int p_kind = 0;
	while(max_need >= mooncake[p_kind].stock && p_kind < n)
	{
		max_need -= mooncake[p_kind].stock;
		total_price += mooncake[p_kind].total_price;
		p_kind++;
	}
	if(p_kind < n) total_price += (max_need * mooncake[p_kind].unit_price);
	
	printf("%.2f", total_price);
	return 0;
}
