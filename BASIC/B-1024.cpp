#include<stdio.h>
#include<string.h>

int main()
{
	char c, sign1, sign2, s[9999];
	int index, in, t, len;
	
	sign1 = getchar();
	scanf("%d.", &in);
	for(int i=0; (c = getchar())!='E'; i++) s[i] = c;
	sign2 = getchar();
	scanf("%d", &index);
	
	if(sign1 == '-') printf("%c",sign1);
	if(sign2 == '-' & index != 0)
	{
		printf("0.");
		for(int i=0; i<index-1; i++) printf("0");
		printf("%d%s", in, s);
	}
	else
	{
		len = strlen(s);

		printf("%d", in);
		if(len <= index)
		{
			printf("%s",s);
			t=index-len;
			for(int i=0; i<t; i++) printf("0");
		}
		else
		{
			int i;
			for(i=0; i<index; i++) putchar(s[i]);
			printf(".");
			for(; i<=len; i++) putchar(s[i]);
		}
	}
	return 0;
}
