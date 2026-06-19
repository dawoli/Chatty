#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1;i <= n;i++)
	{
		int x = s[i] - '0';
		if(x >= 0 && x <= 9)
		{
			a[x]++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		while(a[i]--)
		{
			cout << i;
		}
	}
} 
