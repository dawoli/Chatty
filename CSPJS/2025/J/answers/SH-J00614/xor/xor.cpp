#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n,k,a[N],ans,s,l;
bool re,b[N];
struct node{
	ll l,r,num;
	bool b;
}tr[4*N],u;
node merge(node a,node b)
{
	return (node){a.l,b.r,(a.num^b.num),(a.b==1||b.b==1)};
}
node bt(ll l,ll r,ll x)
{
	if(l == r)
	{
		return tr[x] = (node){l,r,a[l],0};
	}
	ll mid = (l+r)/2;
	return tr[x] = merge(bt(l,mid,x<<1),bt(mid+1,r,x<<1|1));
}
node query(ll l,ll r,ll x)
{
	if(re) return (node){0,0,0,1};
	if(tr[x].l > r || tr[x].r < l) return tr[0];
	if(re) return (node){0,0,0,1};
	if(tr[x].l >= l && tr[x].r <= r)
	{
		if(tr[x].b == 1)
		{
			re = 1;
			return (node){0,0,0,1};
		}
		return tr[x];
	}
	if(re) return (node){0,0,0,1};
	return merge(query(l,r,x<<1),query(l,r,x<<1|1));
	if(re) return (node){0,0,0,1};
}
node upd(ll l,ll r,ll x)
{
	if(tr[x].l > r || tr[x].r < l) return tr[x];
	if(tr[x].l >= l && tr[x].r <= r)
	{
		tr[x].b = 1;
		return tr[x];
	}
	return tr[x] = merge(upd(l,r,x<<1),upd(l,r,x<<1|1));
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i = 1 ; i <= n ; i++) scanf("%lld",&a[i]);
	bt(1,n,1);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n-i+1 ; j++)
		{
			if(!b[j] && !b[j+i-1])
			{
				re = 0;
				u = query(j,j+i-1,1);
				if(u.b == 0 && u.num == k)
				{
					ans++;
					upd(j,j+i-1,1);
					b[j] = b[j+i-1] = 1;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
