#include <bits/stdc++.h>
using namespace std;
int a[16];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for (int i = 0;i<=15;i++)
		a[i]=0;
	cin >> s;
	for (int i = 0;i<s.length();i++)
	{
		if ('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-'0']+=1;
		}
	}	
	for (int i = 9;i>=0;i--)
	{
		while (a[i]>0)
		{
			cout << i;
			a[i]-=1;
		}
	}
	return 0; 
}
