#include<stdio.h>
#include<math.h>

typedef struct
{
	long long k, a, b;
}R;

long long GCD(long long x, long long y)
{
	long long t;
	while(y!=0)
	{
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}
void putR(R n)
{
	if(n.b == 0) printf("Inf");
	else if(n.a == 0) printf("0");
	else 
	{
		long long m = GCD(n.a, n.b);
		long long s = 1;
		n.a /= m;
		n.b /= m;
		if(n.a * n.b < 0) s = -1;
		if(n.a < 0) n.a *= -1;
		if(n.b < 0) n.b *= -1;
		n.k = n.a / n.b * s;
		n.a %= n.b;
		
		if(s<0) printf("(");
		if(n.k==0)
		{
			n.a *= s;
			printf("%d/%d", n.a, n.b);
		}
		else if(n.a == 0)
			printf("%d", n.k);
		else 
			printf("%d %d/%d", n.k, n.a, n.b);
		if(s<0) printf(")");
	}
}
void print(R x, R y, char c)
{
	R n;
	putR(x);
	printf(" %c ", c);
	putR(y);
	printf(" = ");
	switch(c)
	{
		case '+':
			n.b = x.b * y.b;
			n.a = x.a * y.b + x.b * y.a;
			putR(n);
			printf("\n");
			break;
		case '-':
			n.b = x.b * y.b;
			n.a = x.a * y.b - x.b * y.a;
			putR(n);
			printf("\n");
			break;
		case '*':
			n.a = x.a * y.a;
			n.b = x.b * y.b;
			putR(n);
			printf("\n");
			break;
		case '/':
			n.a = x.a * y.b;
			n.b = x.b * y.a;
			putR(n);
			break;
	}
}

int main()
{
	R x, y;
	scanf("%lld/%lld", &x.a, &x.b);
	scanf("%lld/%lld", &y.a, &y.b);
	print(x, y, '+');
	print(x, y, '-');
	print(x, y, '*');
	print(x, y, '/'); 
}  
