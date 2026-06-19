#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,sum;
int f[105];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>f[i];
		if(f[i]>f[1])sum++;
	}
	v=sum/n+1;
	u=sum%n;u++;
	if((v&1)==0)u=n+1-u;
	cout<<v<<" "<<u;
	return 0;
}
