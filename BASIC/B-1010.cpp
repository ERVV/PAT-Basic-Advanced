#include<stdio.h>

int main()
{
  int m, n, count = 0;
  bool out = false;
  char c;
  
  do{
    scanf("%d %d", &m, &n);
    int coe = m * n;
    int index = n - 1;
    if(n!=0)
    {
      if(out) printf(" ");
      else out = true;
      printf("%d %d", coe, index);
    }
    count++;
  }while(getchar() == ' ');
  if(n == 0 && count == 1) printf("0 0");
  return 0;
} 
