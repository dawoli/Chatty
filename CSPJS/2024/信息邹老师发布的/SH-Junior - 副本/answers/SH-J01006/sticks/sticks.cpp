#include <bits/stdc++.h>
using namespace std;
int n2s[15][3] = {{0,6},//
				  {1,2},//
				  {2,5},//
				  {3,5},
				  {4,4},//
				  {5,5},
				  {6,6},//
				  {7,3},//
				  {8,7},//
				  {9,6}}; 
int usest[8] = {0,-1,1,7,4,2,6,8};
int uses[14] = {0,0,0,0,0,0,0,0,10,18,22,20,28,68};
//正常情况下用0,1,2,4,7 6针对前导零 

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		if(n < 8)
		{
			cout << usest[n] << endl;
			continue;
		}
		if(n % 7 == 0)
		{
			for(int i = 1; i <= n / 7; i++)
				cout << '8';
			cout << endl;
			continue;
		}
		int b = (n-7) % 7 + 7;
		int c = (n-7) / 7;
		cout << uses[b];
		for(int i = 1; i <= c; i++)
			cout << 8;
		cout << endl;
	}
	return 0;
}
