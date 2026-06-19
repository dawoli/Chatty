#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	ll s,e;
}gro[500005];
vector<ll> v[1049000];
ll n,k,a[500005],qzh[500005],p[500005];
ll pre,l,r,num,ok,fin,mid,ans;
bool cmp(node c1,node c2)
{
	if(c1.e!=c2.e) return c1.e<c2.e;
	else return c1.s>c2.s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		qzh[i]=qzh[i-1]^a[i];
		v[qzh[i]].push_back(i);
		//cout<<i<<" "<<qzh[i]<<endl;
	}
	for(int i=1;i<=1048600;i++)
	{
		if(v[i].size()<=1) continue;
		for(int j=0;j<v[i].size();j++) p[j+1]=v[i][j];
		sort(p+1,p+v[i].size()+1);
		for(int j=0;j<v[i].size();j++) v[i][j]=p[j+1];
	}
	for(int i=1;i<=n;i++)
	{
		ok=-1;
		fin=k^qzh[i];
		l=0;
		r=v[fin].size()-1;
		while(l<=r)
		{
			mid=l+r>>1;
			//if(i==1) cout<<mid<<endl;
			if(v[fin][mid]<i)
			{
				ok=v[fin][mid]+1;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(ok>=0)
		{
			gro[++num].s=ok;
			gro[num].e=i;
			//cout<<gro[num].e<<" "<<gro[num].s<<endl;
		}
	}
	sort(gro+1,gro+num+1,cmp);
	pre=0;
	for(int i=1;i<=num;i++)
	{
		if(gro[i].s>pre)
		{
			ans++;
			pre=gro[i].e;
		}
	}
	printf("%lld",ans);
	return 0;
} 
