#include<stdio.h>
#include<ctype.h>

int main()
{
	char c, maxchar, max = 0;
	int i, alpha[26] = {0};
	while((c = getchar()) != '\n')
	{
		if(isalpha(c))
		{
			if(isupper(c)) i = c - 'A';
			else i = c - 'a';
			alpha[i]++;
			if(alpha[i] > max)
			{
				max = alpha[i];
				maxchar = 'a' + i;
			}
			else if(alpha[i] == max && maxchar > ('a' + i))
				maxchar = 'a' + i;
		}
	}
	printf("%c %d", maxchar, max);
	return 0;
}
