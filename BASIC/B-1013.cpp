#include<stdio.h>

bool isprime(int x){
	bool ret = true;
	if(x==2 || x==3) ret = true;
	else if(x%2 == 0) ret = false;
	else {
		for(int i=3; i*i<=x; i+=2)
		{
			if(x%i==0)
			{
				ret = false;
				break;
			}
		}
	}
	return ret;
}
int main(){
	int m, n;
	int prime_count = 0;
	int printed_count = 0;
	
	scanf("%d %d", &m, &n);
	int i = 2;
	while(prime_count<n)
	{
		if(isprime(i))
		{
			prime_count++;
			if(prime_count>=m)
			{
				if(printed_count % 10 != 0) printf(" ");
				else if(printed_count > 0) printf("\n");
				printf("%d", i);
				printed_count++;
			}
		}
		i++;
	}
	return 0;
}
