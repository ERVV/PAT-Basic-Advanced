#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	string A;
	int B;
	cin >> A >> B;
	int R = 0, q;
	for(int i=0; i<A.length(); i++)
	{
		R *= 10;
		R += (A[i]-'0');
		q = R / B;
		R %= B;
		if(i+q != 0) printf("%d", q);
	}
	if(q==0 && A.length()==1) printf("0");
	printf(" %d", R);
	return 0;
}
