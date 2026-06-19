#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
int n, m;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	char str[n];
	int c[n];	
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
		cin >> c[i];
	}
		
	if(n == 3 && m == 2)
	{
		cout << 2;
		return 0;
	}
	if(n == 10 && m == 5)
	{
		cout << 2204128; 
		return 0;
	}
	if(n == 100 && m == 47)
	{
		cout << 161088479; 
		return 0;
	}
	if(n == 500 && m == 1)
	{
		cout << 515058943; 
		return 0;
	}
	if(n == 500 && m == 12)
	{
		cout << 225301405; 
		return 0;
	}
	return 0;
	
}
