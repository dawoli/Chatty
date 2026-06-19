#include<bits/stdc++.h>
using namespace std;
const int MAXN=0,MOD=0;
int lst[10];
string s;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int main()
{
	init();
	cin>>s;
	int n=s.length();
	s=' '+s;
	for (int i=1;i<=n;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			lst[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=lst[i];j++)
		{
			cout<<(char)('0'+i);
		}
	}
	return 0;
}
