#include<stdio.h>
#include<ctype.h>
#include<string.h>

long long trans(char *s, long long radix, bool tag, long long top)
{
	long long sum = 0;
	for(int i=0; s[i]; i++)
	{
		if(isdigit(s[i]))
			sum = sum * radix + s[i] - '0';
		else if(islower(s[i]))
			sum = sum * radix + s[i] - 'a' + 10;
		if(tag && (sum > top || sum < 0))
			return -1;
	}
	return sum;
}

long long find_radix_start(char *s)
{
	long long ret = 0;
	int tmp;
	for(int i=0; s[i]; i++){
		if(isdigit(s[i]))
			tmp = s[i] - '0';
		else if(islower(s[i]))
			tmp = s[i] - 'a' + 10;
		if(tmp >= ret)
			ret = tmp + 1;
	}
	return ret;
}

int main()
{
	char s1[11], s2[11], tmp[11];
	long long radix, l, r, mid;
	long long n1 = 0, n2 = 0;
	int tag, i;
	scanf("%s %s %d %lld", s1, s2, &tag, &radix);
	if(tag==2)
	{
		strcpy(tmp, s1);
		strcpy(s1, s2);
		strcpy(s2, tmp);
	}
	n1 = trans(s1, radix, false, 0);
	l = find_radix_start(s2);
	r = (n1>l) ? (n1+1):(l+1);
	bool ans = false;
	while(l<=r)
	{
		mid = (l + r) / 2;
		n2 = trans(s2, mid, true, n1);
		if(n2 == n1)
		{
			ans = true;
			break;
		}
		else if(n2==-1)
			r = mid - 1;
		else
			l = mid + 1;
	}
	if(ans)
		printf("%lld\n", mid);
	else
		printf("Impossible");
	return 0;
}
