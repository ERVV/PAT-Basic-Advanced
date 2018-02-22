#include<stdio.h>

int main()
{
	char PY[][8] = {"zero", "one", "two", "three", "four",
					"five", "six", "seven", "eight", "nine"};
	int sum = 0;
	char digit[105];
	scanf("%s", digit);
	for(int i=0; digit[i]; i++)
		sum += (digit[i] - '0');
	int ans[10], cnt = 0;
	while(sum)
	{
		ans[cnt++] = sum % 10;
		sum /= 10;
	}
	if(cnt == 0) printf("zero");
	for(int i=cnt-1; i>=0; i--)
	{
		printf("%s", PY[ans[i]]);
		if(i) printf(" ");
	}
	return 0;
}
