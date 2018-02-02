#include<stdio.h>
#define END -1
//用例可能有多个链表 
typedef struct{
	int address;
	int data;
	int next;
}Node;

int main(){
	Node node[100000];
	int addr[100000];
	int head, n, k;
	int ad, next, q, r;
	int flag = 0, count = 0;
	
	scanf("%d %d %d", &head, &n, &k);
	if(head == END) printf("%d", END);
	else
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &ad);
			node[ad].address = ad;
			scanf("%d %d", &node[ad].data, &node[ad].next); 
		}
	
		for(int i=0, next=head; next!=END; i++)
		{
			addr[i] = next;
			next = node[next].next;
			count++;			
		}
		
		int i;
		for(i=k; i<=count; i+=k)
		{
			for(int j=i-1; j>=i-k; j--)
			{
				if(flag) printf("\n");
				else flag = 1;
				
				if(j % k)
				{
					printf("%05d %d %05d", addr[j], node[addr[j]].data, addr[j-1]);
				}
				else if(j+2*k <= count)
				{
					printf("%05d %d %05d", addr[j], node[addr[j]].data, addr[j+2*k-1]);
				}
				else if(j+k < count)
				{
					printf("%05d %d %05d", addr[j], node[addr[j]].data, addr[j+k]);
				}
				else 
					printf("%05d %d %d", addr[j], node[addr[j]].data, END);
			}
		}
		for(i-=k; i<count; i++)
		{
			if(flag) printf("\n");
			else flag = 1;
			if(node[addr[i]].next == END)
			{
				printf("%05d %d %d", addr[i], node[addr[i]].data, END);
			}else
			{
				printf("%05d %d %05d", addr[i], node[addr[i]].data, node[addr[i]].next);
			} 
		}
	}
	return 0;
} 
