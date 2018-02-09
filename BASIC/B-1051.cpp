#include<stdio.h>
#include<math.h>

struct node
{
	double a, b;
};

int main()
{
	double r, p;
	struct node A[2], ans;
	int i = 2;
	for(i=0;i<2;i++)
	{
		scanf("%lf%lf", &r, &p);
		A[i].a = r * cos(p);
		A[i].b = r * sin(p);
	}
	ans.a = A[0].a * A[1].a - A[0].b * A[1].b;
	ans.b = A[0].a * A[1].b + A[0].b * A[1].a;
	if(ans.a+0.005>0 && ans.a<0)
		printf("%.2lf", ans.a+0.005);
	else
		printf("%.2lf", ans.a);
	if(ans.b+0.005>0 && ans.b < 0)
	{
		printf("+%.2lfi", ans.b+0.005);
	}
	else if(ans.b > 0)
	{
		printf("+%.2lfi", ans.b);
	}
	else if(ans.b < 0)
	{
		printf("%.2lfi", ans.b);
	}
	return 0;
}
