#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],l,r,mid,id,ans;
bool f[100005];
ll find(ll id)
{
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]>a[id]&&!f[mid]) r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		id=find(i);
		if(id>n) ans++;
		f[id]=1;
	}
	printf("%lld\n",ans);
	return 0;
}
