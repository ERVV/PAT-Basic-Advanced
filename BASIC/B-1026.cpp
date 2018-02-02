#include<stdio.h>
#define CLK_TCK 100

int main(){
	int c1, c2;
	int hour, minute, second, time;
	int r;
	scanf("%d %d", &c1, &c2);
	time = (c2 - c1 + 50) / CLK_TCK;
	second = time % 60;
	time /= 60;
	minute = time % 60;
	hour = time / 60;
	
	printf("%02d:%02d:%02d", hour, minute, second);
	return 0;
} 
