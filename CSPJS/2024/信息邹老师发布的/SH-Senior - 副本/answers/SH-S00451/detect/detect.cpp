#include <bits/stdc++.h>
using namespace std;
const double err=0.00001;
int t,n,m,L,V,d[100009],v[100009],a[100009],cnt,ans,ans2,p,minr[100009];
struct range
{
	int l,r;
	bool operator<(const range x)const
	{
		return l<x.l||l==x.l&&r<x.r;
	}
}rg[100009],drg[100009];
range cal(int d,int v,int a)
{
	if(a==0&&v>V)return (range){d,L};
	else if(a==0)return (range){0,0};
	double ans=d+(V*V-v*v)/2.0/a;
	if(a<0&&ans+err<d||a>0&&ans-err>L)return (range){0,0};
	else if(a<0)return (range){d,(int)floor(ans-err)};
	else return (range){(int)ceil(ans+err),L};
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		cnt=ans=ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
			range rg1=cal(d[i],v[i],a[i]);
			if(rg1.r)rg[++cnt]=rg1;
		}
		int s[100009]={};
		for(int i=1;i<=m;i++)cin>>p,s[p]=1;
		for(int i=1;i<=L;i++)s[i]+=s[i-1];
		for(int i=1;i<=cnt;i++)
			if(s[rg[i].r]>s[rg[i].l-1])
				drg[++ans]=(range){s[rg[i].l-1]+1,s[rg[i].r]};
		cout<<ans<<' ';
		sort(drg+1,drg+1+ans);
		minr[ans+1]=2e9;
		for(int i=ans;i>=1;i--)minr[i]=min(minr[i+1],drg[i].r);
		int j=0;
		for(int i=1;i<=ans&&j<=L;)
		{
			while(drg[i].l<=j&&i<=ans)i++;
			j=minr[i];
			ans2++;
		}
		cout<<ans2<<endl;
	}
	return 0;
}
