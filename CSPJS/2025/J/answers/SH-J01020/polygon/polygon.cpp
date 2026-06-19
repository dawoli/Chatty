#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[5005],c[5005],t,x,VIS[5005];
void OIO(ll u,ll k)
{
	if(u>n)return;
	if(k>a[u])t++;
	OIO(u+1,k);
	if(VIS[u]==0)
	{
		VIS[u]=1;
		OIO(u+1,k+a[u]);
		VIS[u]=0;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	OIO(1,0);
	cout<<t;
	return 0; 
} 
