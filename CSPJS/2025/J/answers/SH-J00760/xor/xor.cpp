#include <bits/stdc++.h>
using namespace std;
struct ss
{
	int l,r;
}s[500005];
bool com1(ss x,ss y)
{
	if(x.r==y.r) return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int num=0;
	int a[500005];
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(k==0&&flag) cout<<n/2;
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int tem=a[i];
				for(int k=i+1;k<=j;k++) tem=tem^a[k];
				if(tem==k)
				{
					s[++num].l=i;
					s[num].r=j;
				}
			}
		}
		sort(s+1,s+1+num,com1);
		int ll=s[num].l;
		int ans=1;
		for(int i=num-1;i>=1;i--)
		{
			if(s[i].r<ll)
			{
				ans++;
				ll=s[i].l;
			}
		}
		cout<<ans;
	}
	return 0;
}
