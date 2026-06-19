#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cur=0;
	for (unsigned int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')	a[++cur]=s[i]-'0';
	}
	sort(a+1,a+cur+1,cmp);
	string ans="";
	if (a[1]==0)	{cout<<0<<endl;return 0;}
	for (int i=1;i<=cur;i++)
	{
		ans+=char(a[i]+'0');
	}
	cout<<ans<<endl;
	return 0;
}

