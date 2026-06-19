#include <bits/stdc++.h>
using namespace std;
int f[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(f,0,sizeof(f));
	string s;
	getline(cin,s);
	int n = s.length();
	for (int i = 0;i < n;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			f[int(s[i]) - int('0')]++;
		}
	 } 
	for (int i = 9;i >= 0;i--)
	{
		while(f[i]>0)
		{
			printf("%d",i);
			f[i]--;
		}
	}
	return 0;
 } 
