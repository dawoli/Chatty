#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
int T,n,m,L,vm;
int ans1=0,ans2=0,p[maxn],det[maxn];
bool flag[maxn];
double cal(int d,int v,int a)
{
	return(d+(vm*vm-v*v)/(2*a));
}
int main()
{	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int d[maxn],v[maxn],a[maxn];
	scanf("%d",&T);
	while(T--)
	{
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		memset(det,0,sizeof(det));
		ans1=0,ans2=0;
		scanf("%d %d %d %d",&n,&m,&L,&vm);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i]);
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			bool sign=0;
			if(v[i]>vm && a[i]>=0)
			{
				for(int j=1;j<=m;j++)
				{
					if(p[j]>=d[i])sign=1,flag[j]=1,det[i]++;
				}
			}
			else if(v[i]<=vm && a[i]<=0)continue;
			else if(v[i]>vm && a[i]<0)
			{
				double r=cal(d[i],v[i],a[i]);
				for(int j=1;j<=m;j++)
				{
					if(p[j]>=d[i] && (double)p[j]<r)flag[j]=1,sign=1,det[i]++;
					if(p[j]>=r)break;
				}
			}
			else if(v[i]<=vm && a[i]>0)
			{
				double r=cal(d[i],v[i],a[i]);
				for(int j=1;j<=m;j++)
				{
					if((double)p[j]>r)sign=1,flag[j]=1,det[i]++;
				}
			}
			if(sign)ans1++;
		}
		for(int i=1;i<=m;i++)
		{
			if(!flag[i])ans2++;
		}
		sort(det+1,det+n+1);
		ans2+=det[n]/2;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
 } 
