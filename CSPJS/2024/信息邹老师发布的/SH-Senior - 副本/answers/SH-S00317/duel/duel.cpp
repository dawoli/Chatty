#include<bits/stdc++.h>
using namespace std;
bool a[100005];
int n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	memset(a,false,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]=true;
	}
	int ans=0;
	for(int i=1;i<=100000;i++)
	{
		if(a[i]==true) ans++;
	}
	cout<<n-ans;
	return 0;
}
