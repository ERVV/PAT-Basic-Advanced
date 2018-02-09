#include<stdio.h>

int main()
{
	long long gal1, sic1, knut1;
	long long gal2, sic2, knut2;
	long long gal3, sic3, knut3;
	long long need, pay, n;
	scanf("%lld.%lld.%lld", &gal1, &sic1, &knut1);
	scanf("%lld.%lld.%lld", &gal2, &sic2, &knut2);
	need = knut1 + 29 * (sic1 + 17 * gal1);
	pay = knut2 + 29 * (sic2 + 17 * gal2);
	if(need > pay)
	{
		n = need - pay;
		printf("-");
	}
	else n = pay - need;
	knut3 = n % 29;
	n /= 29;
	sic3 = n % 17;
	gal3 = n / 17;
	printf("%lld.%lld.%lld",gal3, sic3, knut3);
	return 0;
}
