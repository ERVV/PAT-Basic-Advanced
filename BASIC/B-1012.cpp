#include<stdio.h>

int main()
{
	int A1_sum = 0, A2_sum = 0, A3_count = 0, A5_max = 0;
	float A4_average = 0.0;
	int A2_1 = 1, A2_flag = false, A4_count = 0;
	float A4_sum = 0.0;

	int num;	
	scanf("%d", &num);
	while(num--)
	{
		int n;
		scanf("%d", &n);
		switch(n%5)
		{
			case 0:
				if(n%2==0) A1_sum += n;
				break;
			case 1:
				A2_flag = true;
				A2_sum += (A2_1*n);
				A2_1 *= -1;
				break;
			case 2:
				A3_count++;
				break;
			case 3:
				A4_sum += n;
				A4_count++;
				break;
			case 4:
				if(n > A5_max) A5_max = n;
				break;
		}
	}
	A4_average = A4_sum / A4_count;
	
	if(A1_sum != 0) printf("%d", A1_sum);
	else printf("N"); 
	if(A2_flag) printf(" %d", A2_sum);
	else printf(" N");
	if(A3_count != 0) printf(" %d", A3_count);
	else printf(" N");
	if(A4_count != 0) printf(" %.1f", A4_average);
	else printf(" N");
	if(A5_max != 0) printf(" %d", A5_max);
	else printf(" N");

	return 0;
}
