#include<stdio.h>
#include<ctype.h>

int judge(char *s)
{
	int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 
					  3, 7, 9, 10, 5, 8, 4, 2};
	int sum = 0;
	bool flag = true;
	char m[11] = {'1', '0', 'X', '9', '8',
				  '7', '6', '5', '4', '3', '2'};
	for(int i=0; i<17 && flag; i++)
	{
		if(isdigit(s[i]))
			sum += (weight[i] * (s[i] - '0'));
		else
			flag = false;
	}
	if(flag && s[17]!=m[sum%11]) flag = false; 
	return flag;
}

int main()
{
	char id[100][20];
	int N; 
	bool flag = false;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%s", id[i]);
	for(int i=0; i<N; i++){
		if(!judge(id[i]))
		{
			if(flag) printf("\n");
			else flag = true;
			printf("%s", id[i]);
		}
	}
	if(!flag) printf("All passed");
	return 0;
} 
