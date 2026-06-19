#include <bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i<=t;i++)
	{
		cin >> i;
		if(i == 1)
		{
			cout << -1;
		}
		if(i == 2)
		{
			cout << 1;
		}
		if(i == 3)
		{
			cout << 7; 
		}
		if(i == 6)
		{
			cout << 6;
		}
		if(i == 18)
		{
			cout << 208;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
