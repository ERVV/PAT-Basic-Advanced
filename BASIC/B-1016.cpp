#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int get_D_part(string S, int D)
{
	int sum = 0;
	for(int i=0; i<S.length();i++)
	{
		if(S[i]-'0' == D) 
		{
			sum *= 10;
			sum += D;
		}
	}
	return sum;
}


int main()
{
	string A, B;
	int DA, DB;
	cin >> A >> DA >> B >> DB;
	
	cout << get_D_part(A, DA) + get_D_part(B, DB);
	return 0;
} 
