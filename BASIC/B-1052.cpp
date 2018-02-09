#include<stdio.h>

int main()
{
	char c, eye[10][5], hand[10][5], mouth[10][5];
	int cnte = 0, cnth = 0, cntm = 0;
	int i;
	while((c = getchar())!='\n')
	{
		if(c=='[')
		{
			i = 0;
			while((c=getchar())!=']')
			{
				hand[cnth][i++] = c;
			}
			hand[cnth++][i] = 0;
		}
	}
	while((c = getchar())!='\n')
	{
		if(c=='[')
		{
			i = 0;
			while((c=getchar())!=']')
			{
				eye[cnte][i++] = c;
			}
			eye[cnte++][i] = 0;
		}
	}
	while((c = getchar())!='\n')
	{
		if(c=='[')
		{
			i = 0;
			while((c=getchar())!=']')
			{
				mouth[cntm][i++] = c;
			}
			mouth[cntm++][i] = 0;
		}
	}
	int n;
	int q[5];
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d%d%d%d", &q[0], &q[1], &q[2], &q[3], &q[4]);
		if(q[0]>0&&q[1]>0&&q[2]>0&&q[3]>0&&q[4]>0 && q[0]<=cnth && q[1]<=cnte && q[2]<=cntm && q[3]<=cnte && q[4]<=cnth)
		{
			printf("%s(%s%s%s)%s\n", hand[q[0]-1], eye[q[1]-1], mouth[q[2]-1], eye[q[3]-1], hand[q[4]-1]);
		}
		else 
			printf("Are you kidding me? @\\/@\n");
	}
	return 0;
}
