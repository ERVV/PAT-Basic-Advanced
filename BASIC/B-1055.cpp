#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int height;
	char name[10];
}record;


int cmp(const void *a, const void *b)
{
	record *aa = (record*)a;
	record *bb = (record*)b;
	if(aa->height!=bb->height)
	{
		return (aa->height>bb->height)?-1:1;
	}
	else return strcmp(aa->name, bb->name);
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	record *stu = (record*)malloc(n*sizeof(record));
	int *ans = (int*)malloc(n*sizeof(int));
	int *row = (int*)malloc(k*sizeof(int));
	row[0] = n / k;
	int i, j;
	for(i=1;i<k;i++) row[i] = row[0];
	row[0] += n%k;
	for(i=0;i<n;i++)
		scanf("%s %d", stu[i].name, &stu[i].height);
	qsort(stu, n, sizeof(stu[0]), cmp);
	int mid, have = 0;
	j=0;
	for(i=0;i<k;i++)
	{
		int offset = 0;
		mid = row[i] / 2;
		while(mid+offset >=0 && mid+offset<row[i])
		{
			ans[have+mid+offset] = j++;
			if(offset>=0)
			{
				offset++;	
			}
			offset *= -1;
		}
		have += row[i];
	}
	have = 0;
	for(i=0;i<k;i++)
	{
		for(j=0;j<row[i];j++)
		{
			if(j) printf(" ");
			printf("%s", stu[ans[have+j]].name);
		}
		printf("\n");
		have += row[i];
	}
	return 0;
}
