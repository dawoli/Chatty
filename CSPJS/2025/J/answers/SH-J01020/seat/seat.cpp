#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,R,a[1005][1005];
ll MP[100005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			MP[a[i][j]]++;
		}
	}
	for(int i=10000;i>=1;i--)MP[i]+=MP[i+1];
	cout<<(MP[a[1][1]]/n+(MP[a[1][1]]%n!=0))<<" ";
	if((MP[a[1][1]]/n+(MP[a[1][1]]%n!=0))%2==1)
	{
		if(MP[a[1][1]]%n==0)
		cout<<n;
		else cout<<MP[a[1][1]]%n;
	}
	else
	{
		if(MP[a[1][1]]%n==0)
		{
			cout<<1;
		} 
		else
		cout<<n-MP[a[1][1]]%n+1;
	}
	return 0;
}
