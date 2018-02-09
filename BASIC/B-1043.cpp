#include<stdio.h>

int main()
{
	char c, alpha[6] = {'P', 'A', 'T', 'e', 's', 't'};
	int count[6] = {0};
	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			case 'P': count[0]++; break;
			case 'A': count[1]++; break;
			case 'T': count[2]++; break;
			case 'e': count[3]++; break;
			case 's': count[4]++; break;
			case 't': count[5]++; break;
		}
	}
	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i=0; i<6; i++)
		{
			if(count[i])
			{
				flag = true;
				count[i]--;
				printf("%c", alpha[i]);
			}
		}
	}
	return 0;
} 
