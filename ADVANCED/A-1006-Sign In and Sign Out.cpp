#include<stdio.h>

typedef struct{
	int h, m, s;
}Time;
typedef struct{
	char ID[16];
	Time in, out;
}Record;

bool is_later(Time A, Time B)
{
	bool t;
	if(A.h != B.h) 
		t = (A.h > B.h) ? true:false;
	else if(A.m != B.m) 
		t = (A.m > B.m) ? true:false;
	else t = (A.s > B.s) ? true:false;
	return t;
}
int main()
{
	int M;
	Record firstin, lastout, t;
	scanf("%d", &M);
	for(int i=0; i<M; i++)
	{
		scanf("%s", t.ID);
		scanf("%d:%d:%d", &t.in.h, &t.in.m, &t.in.s);
		scanf("%d:%d:%d", &t.out.h, &t.out.m, &t.out.s);
		if(!i) 
		{
			firstin = t;
			lastout = t;
		}
		else
		{
			if(is_later(firstin.in, t.in))
				firstin = t;
			if(is_later(t.out, lastout.out))
				lastout = t;
		}
	}
	printf("%s %s", firstin.ID, lastout.ID);
	return 0;
}
