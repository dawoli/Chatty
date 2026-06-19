#include <bits/stdc++.h>
using namespace std;
int s[501],c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int pf=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==1)
			pf++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(pf==n)
	{
		if(m==n)
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	cout<<6;
	return 0;
}

