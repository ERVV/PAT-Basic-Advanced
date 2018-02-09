#include<stdio.h>

int main()
{
	char ch, c[101];
	int a[101], b[101], r;
	int i, lena, lenb, len;
	for(i=0;(ch = getchar())!=' ';i++)
	{
		a[i] = ch - '0';
	}
	lena = i;
	for(i=0;(ch = getchar())!='\n';i++)
	{
		b[i] = ch - '0';
	}
	lenb = i;
	len = (lena>lenb)?lena:lenb;
	c[len] = '\0';
	for(i=1;i<=lena && i<=lenb;i++)
	{
		if(i%2 == 0)
		{
			r = (b[lenb-i] - a[lena-i] + 10) % 10;
			c[len-i] = '0' + r;
		}
		else
		{
			r = (a[lena-i] + b[lenb-i]) % 13;
			switch(r)
			{
				case 10: c[len-i] = 'J';break;
				case 11: c[len-i] = 'Q';break;
				case 12: c[len-i] = 'K';break;
				default: c[len-i] = '0' + r;break;
			}
		}
	}
	while(i<=lena)
	{
		if(!(i%2))
		{
		 	r = (10 - a[len-i]) % 10;
		}
		else r = a[len-i];
		c[len-i] = '0' + r;
		i++;
	} 
	while(i<=lenb)
	{
		c[len-i] = '0' + b[lenb-i];
		i++;
	}
	printf("%s", c);
	return 0;
} 
