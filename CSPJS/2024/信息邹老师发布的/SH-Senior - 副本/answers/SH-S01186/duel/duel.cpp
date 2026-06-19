#include<bits/stdc++.h>
using namespace std;
int n,a[100003],s;
int main()
{
	s=0;
	memset(a,0,sizeof(a));
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		a[x]++;
	}
	for(int i=1;i<=100000;i++)
	{
		s=max(s,a[i]);
	}
	cout<<s;
	return 0;
}
