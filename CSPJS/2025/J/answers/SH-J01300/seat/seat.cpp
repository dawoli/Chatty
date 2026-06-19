#include<bits/stdc++.h>
using namespace std;
int n,m,s,id,x,y;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i)
		if(s==a[i])
		{
			id=n*m-i;
			break;
		}
	x=id/n+1;id%=n;
	cout<<x<<' ';
	if(x%2==0) cout<<n-id;
	else cout<<id+1;
	return 0;
}
