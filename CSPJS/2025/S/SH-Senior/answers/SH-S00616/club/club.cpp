#include <bits/stdc++.h>
using namespace std;
const int maxn=100006;
using lll=long long;
int a[maxn],b4[maxn],c4[maxn];
int ll[4];
struct id1
{
	int fa1;
	int nu1;
	int fa2;
	int nu2;
	int fa3;
	int nu3;
}b[maxn];
struct id2
{
	int fa;
	int people;
}c[maxn];
bool cmp1(id2 a,id2 b)
{
	return a.fa>b.fa;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(ll,0,sizeof(ll));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(b4,0,sizeof(b4));
		memset(c4,0,sizeof(c4));
		int n;
		cin>>n;
		int sum2=0,sum3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b4[i]>>c4[i];
			int b1=a[i],b2=b4[i],b3=c4[i];
			sum2+=b4[i],sum3+=c4[i];
			if(b1>b2&&b1>b3){
				c[i].fa=b1,c[i].people=i;
				b[i].fa1=b1,b[i].nu1=1;
				if(b2>b3) b[i].fa2=b2,b[i].nu2=2,b[i].fa3=b3,b[i].nu3=3;
			}
			else if(b2>b1&&b2>b3) {
				c[i].fa=b2,c[i].people=i;
				b[i].fa1=b2,b[i].nu1=2;
				if(b1>b3) b[i].fa2=b1,b[i].nu2=1,b[i].fa3=b3,b[i].nu3=3;
			}
			else {
				c[i].fa=b3,c[i].people=i;
				b[i].fa1=b3,b[i].nu1=3;
				if(b1>b2) b[i].fa2=b1,b[i].nu2=1,b[i].fa3=b2,b[i].nu3=2;
			}
		}
		lll ans=0;
		if(sum2==0&&sum3==0)
		{
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
			break;
		}
		sort(c+1,c+n+1,cmp1);
		int kk=n/2;
		for(int i=1;i<=n;i++)
		{
			if(ll[b[c[i].people].nu1]<kk)
			{
				ll[b[c[i].people].nu1]++;
				ans+=b[c[i].people].fa1;
			}
			else
			{
				if(ll[b[c[i].people].nu2]<kk)
			    {
				    ll[b[c[i].people].nu2]++;
				    ans+=b[c[i].people].fa2;
			    }
			    else
			    {
			    	ll[b[c[i].people].nu3]++;
				    ans+=b[c[i].people].fa3;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
