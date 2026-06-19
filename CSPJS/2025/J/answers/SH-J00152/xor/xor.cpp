#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],tail;
ll z[1000010],t;
struct Node
{
	int l,r;
}qj[1000010];
bool cmp(Node x,Node y)
{
	if(x.r!=y.r)
		return x.r>y.r;
	return x.l>y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		ll sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				tail++;
				qj[tail].l=i;
				qj[tail].r=j;
			}
		}
	}
	sort(qj+1,qj+tail+1,cmp);
	qj[0].l=qj[0].r=1e9;
	for(int i=1;i<=tail;i++)
	{
		ll l=0,r=t,pos=0;
		while(l<=r)
		{
			ll m=(l+r)/2;
			if(qj[z[m]].l>qj[i].r)
			{
				pos=m;
				l=m+1;
			}
			else
				r=m-1;
		}
		if(pos==t)
			z[++t]=i;
		else if(qj[i].l>qj[z[pos+1]].l)
			z[pos+1]=i;
	}
	cout<<t;
	return 0;
}
