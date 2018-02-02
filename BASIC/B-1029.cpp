#include<stdio.h>
#include<ctype.h>

int main()
{
	char s[81], t[81], a[40];
	int count = 0;
	bool flag;
	scanf("%s%s", s, t);
	for(int i=0, j=0; s[i]!='\0'; i++)
	{
		if(islower(s[i])) s[i] += ('A' - 'a');
		if(islower(t[j])) t[j] += ('A' - 'a');
		if(s[i] == t[j]) j++;
		else
		{
			flag = true;
			int k;
			for(k=0; k<count; k++)
			{
				if(a[k] == s[i])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				count++;
				a[k] = s[i];
			}
		}
	}
	for(int i=0; i<count; i++) printf("%c", a[i]);
	return 0;
} 
