#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct{
	int num;
	int grade_de, grade_cai, total;
	int rank;
}record;

bool cmp1(record x, record y)
{
	if(x.rank != y.rank) 
		return x.rank > y.rank;
	else if(x.total != y.total)
		return x.total > y.total;
	else if(x.grade_de != y.grade_de)
		return x.grade_de > y.grade_de;
	else return x.num < y.num;
}

int main()
{
	int n, L, H, pass_count = 0;
	scanf("%d %d %d", &n, &L, &H);
	record stu[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d", &stu[i].num, &stu[i].grade_de, &stu[i].grade_cai);
		stu[i].total = stu[i].grade_de + stu[i].grade_cai;
		
		stu[i].rank = 0;
		if(stu[i].grade_de>=L && stu[i].grade_cai>=L)
		{
			pass_count++;
			stu[i].rank++;
			if(stu[i].grade_de<H && stu[i].grade_cai<H && stu[i].grade_de>=stu[i].grade_cai)	
				stu[i].rank += 1;
			else if(stu[i].grade_de>=H && stu[i].grade_cai<H) 
				stu[i].rank += 2;
			else if(stu[i].grade_de>=H && stu[i].grade_cai>=H) 
				stu[i].rank += 3;
		}
	}
	sort(stu, stu+n, cmp1);
	
	printf("%d\n", pass_count);
	for(int i=0;i<pass_count;i++)
	{
		if(i!=0) printf("\n");
		printf("%d %d %d", stu[i].num, stu[i].grade_de, stu[i].grade_cai);
	}
	return 0;
}
