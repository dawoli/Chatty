#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[5];
ll n,a[100005],b[100005],c[100005],t,ans,num,p[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		v[1].clear();
		v[2].clear();
		v[3].clear();
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				num=min(a[i]-b[i],a[i]-c[i]);
				v[1].push_back(num);
				ans+=a[i]; 
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				num=min(b[i]-a[i],b[i]-c[i]);
				v[2].push_back(num);
				ans+=b[i]; 
			}
			else if(c[i]>=b[i]&&c[i]>=a[i])
			{
				num=min(c[i]-b[i],c[i]-a[i]);
				v[3].push_back(num);
				ans+=c[i];
			}
		}
		if(v[1].size()>n/2)
		{
			for(int i=0;i<v[1].size();i++) p[i+1]=v[1][i];
			sort(p+1,p+v[1].size()+1);
			for(int i=1;i<=v[1].size()-n/2;i++) ans-=p[i];
		}
		if(v[2].size()>n/2)
		{
			for(int i=0;i<v[2].size();i++) p[i+1]=v[2][i];
			sort(p+1,p+v[2].size()+1);
			for(int i=1;i<=v[2].size()-n/2;i++) ans-=p[i];
		}
		if(v[3].size()>n/2)
		{
			for(int i=0;i<v[3].size();i++) p[i+1]=v[3][i];
			sort(p+1,p+v[3].size()+1);
			for(int i=1;i<=v[3].size()-n/2;i++) ans-=p[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
 } 
