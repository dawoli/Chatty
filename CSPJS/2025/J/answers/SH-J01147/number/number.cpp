#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
char x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	
	for (int i=9;i>=0;i--)
	{
		for (int j=0;j<s.size();j++)
		{
			if (s[j]=='0'+i)
			{
				cout << i;
			}
		}
	}
	return 0;
}
