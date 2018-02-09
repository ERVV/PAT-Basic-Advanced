#include<stdio.h>

int insertion(int *init, int *sorted, int n)
{
	bool ret = false;
	int tem[100];
	for(int i=0; i<n; i++) tem[i] = init[i];
	for(int i=1; i<n; i++)
	{
		bool flag = true;
		int m = tem[i];
		int j;
		for(j=i; j>0; j--)
			if(tem[j-1] > m) tem[j] = tem[j-1];
			else break;
		tem[j] = m;
		for(j=0; j<n && flag; j++) 
			if(tem[j] != sorted[j]) 
				flag = false;
		if(flag)
		{
			ret = true;
			printf("Insertion Sort\n");
			m = tem[i+1];
			for(j=i+1; j>0; j--)
				if(tem[j-1] > m) tem[j] = tem[j-1];
				else 
					break;
			tem[j] = m;
			for(int j=0; j<n; j++)
			{
				if(j) printf(" ");
				printf("%d", tem[j]);
			}
		}
		if(ret) break;
	}
	return ret;
}

void merge(int *tem, int *sorted, int n)
{
	int step, ls, le, rs, re;
	int t[100];
	for(step=1; step<n; step*=2)
	{
		for(ls=0; ls+step<n; ls=re+1)
		{
			rs = ls + step;
			le = rs - 1;
			re = le + step;
			if(re > n-1) re = n-1;
			int k = 0;
			while(ls<=le && rs<=re) 
				t[k++] = (tem[ls] < tem[rs])?tem[ls++]:tem[rs++];
			while(ls<=le) t[k++] = tem[ls++];
			while(rs<=re) t[k++] = tem[rs++];
			while(k) tem[--rs] = t[--k];
		}
		bool flag = true;
		for(int k=0; k<n; k++)
			if(tem[k] != sorted[k]) flag = false;
		if(flag)
		{
			printf("Merge Sort\n"); 
			for(ls=0, step*=2; ls+step<n; ls=re+1)
			{
				rs = ls + step;
				le = rs - 1;
				re = le + step;
				if(re > n-1) re = n - 1;
				int k = 0;
				while(ls<=le && rs<=re) 
					t[k++] = (tem[ls]<tem[rs])?tem[ls++]:tem[rs++];
				while(ls<=le) t[k++] = tem[ls++];
				while(rs<=re) t[k++] = tem[rs++];
				while(k) tem[--rs] = t[--k];
			}
			break;
		}
	}
	for(int k=0; k<n; k++)
	{
		if(k) printf(" ");
		printf("%d", tem[k]);
	}
}

int main()
{
	int n, init[100], sorted[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &init[i]);
	for(int i=0; i<n; i++) scanf("%d", &sorted[i]);
	if(!insertion(init, sorted, n)) merge(init, sorted, n);
	return 0;
}
