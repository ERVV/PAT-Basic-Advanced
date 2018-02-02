#include<stdio.h>
#include<ctype.h>

int main()
{
	int hash[10] = {0};
	bool flag = false;
	char c;
	while(isdigit(c = getchar())) hash[c-'0']++;
	for(int i=0; i<10; i++)
	{
		if(hash[i]) 
		{
			if(flag) printf("\n");
			flag = true;
			printf("%d:%d", i, hash[i]);
		}
	}
	return 0;
}
