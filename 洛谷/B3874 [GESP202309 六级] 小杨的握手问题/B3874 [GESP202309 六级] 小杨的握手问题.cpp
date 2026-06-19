#include<bits/stdc++.h>
using namespace std;
int a[300001],b[300001],n;
long long ans=0;
void solve(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int tot=l;
	int i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			b[tot++]=a[i++];
		}
		else
		{
			ans+=mid-i+1;
			b[tot++]=a[j++];
		}
	}
	while(i<=mid)
		b[tot++]=a[i++];
	while(j<=r)
		b[tot++]=a[j++];
	for(int t=l;t<=r;t++)
		a[t]=b[t];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	reverse(a+1,a+n+1);
	solve(1,n);
	cout<<ans;
	return 0;
}
