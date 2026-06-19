#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int d,u,a;
}NODE,*PNODE;
int d[100005];
int u[100005];
int a[100005];
int p[100005];
double nowv(double s,int u,int a)
{
	return sqrt((double)u*(double)u+2.0*(double)a*(double)s);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,l,v,n,m,i,j,_max,_min,ans;
	scanf("%d",&t);
	while(t--)
	{
		memset(d,0x00,sizeof(d));
		memset(u,0x00,sizeof(u));
		memset(a,0x00,sizeof(a));
		ans=0;
		_max=INT_MIN,_min=INT_MAX;
		scanf("%d %d %d %d",&n,&m,&l,&v);
		for(i=1;i<=n;++i)
		{
			scanf("%d %d %d",&d[i],&u[i],&a[i]);
			_min=min(_min,a[i]);
			_max=max(_max,a[i]);
		}
		for(i=1;i<=m;++i)
		{
			scanf("%d",&p[i]);
		}
		if(_max==0&&_min==0)
		{
			for(i=1;i<=n;++i)
			{
				if(u[i]>v&&d[i]<=p[m])
				{
					++ans;
				}
			}
			if(ans==0)
			{
				printf("0 %d\n",m);
			}
			else
			{
				printf("%d %d\n",ans,m-1);
			}
		}
		else if(_max>0&&_min>0)
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=m;++j)
				{
					if(p[j]<d[i])
					{
						continue;
					}
					if(nowv(p[j]-(double)d[i],u[i],a[i])>(double)v)
					{
						++ans;
						break;
					}
				}
			}
			if(ans==0)
			{
				printf("0 %d\n",m);
			}
			else
			{
				printf("%d %d\n",ans,m-1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
