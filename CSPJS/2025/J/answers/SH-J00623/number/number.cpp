#include <bits/stdc++.h>
using namespace std;
const int maxn=1000006;
string s;
int a[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lenn=s.length();
	int countt=0;
	for(int i=0;i<lenn;i++)
	{
		if(0<=s[i]-'0'&&s[i]-'0'<=9)
		{
			countt++;
			a[countt]=s[i]-'0';
		}
	}
	sort(a+1,a+countt+1);
	for(int i=countt;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
