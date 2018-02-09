#include<stdio.h>

int main()
{
	double pans = 0, ans = 0;
	int N, D;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	for(int i=0; i<N; i++)
	{
		bool flag = false;
		int cnt = 0;
		int d;
		double data;
		scanf("%d", &d);
		if(d>D) flag = true;
		for(int j=0; j<d; j++)
		{
			scanf("%lf", &data);
			if(data<e) cnt++;
		}
		if(flag && cnt*2 > d)
		{
			ans++;
		}
		else if(cnt*2 > d)
		{
			pans++;
		}
	}
	ans = ans / N * 100;
	pans = pans / N * 100;
	printf("%.1lf%% %.1lf%%", pans, ans);
	return 0;
}
