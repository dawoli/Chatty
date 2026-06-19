#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ans,c=1,r=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(ans==a[1]) return cout<<c<<' '<<r,0;
	for(int i=2;i<=n*m;i++)
	{
		if(c%2==1)
		{
			if(r!=n) r++;
			else c++;
		}
		else
		{
			if(r!=1) r--;
			else c++;
		}
		if(ans==a[i]) break;
	}
	cout<<c<<' '<<r;
	return 0;
}
