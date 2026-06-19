#include<bits/stdc++.h>
#define N 110000

using namespace std;

int T,n,m,l,v0;
int d[N],v[N],a[N];
int p,tot=0;
bool whe[10000];
bool whe1,whe2,whe3;
int lim[10000][30];
int q[30],r[30],ad[30];

int dfs(int k,int sum)
{
	if(k==tot+1)
	{
//		for(int i=1;i<=sum;i++)
//		{
//			cout<<ad[i]<<' ';
//		}
//		cout<<endl;
		return sum;
	}
	for(int i=1;i<=sum;i++)
	{
		if(ad[i]>=lim[r[k]][1]&&ad[i]<=lim[r[k]][lim[r[k]][0]])
		{
			 return dfs(k+1,sum);
		}
	 }
	 int bet=100; 
	 for(int i=1;i<=lim[r[k]][0];i++)
	 {
		 sum++;
	 	ad[sum]=lim[r[k]][i];
//	 	cout<<sum<<ad[sum]<<endl;
	 	bet=min(bet,dfs(k+1,sum));
	 	sum--;
	 }
	 return bet;
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int Time=1;Time<=T;Time++)
	{
		whe1=true;
		whe2=true;
		whe3=true;
		scanf("%d%d%d%d",&n,&m,&l,&v0);
		tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]>0)
			{
				whe2=false;
				whe3=false;
			}
			else if(a[i]==0)
			{
				whe1=false;
				whe3=false;
			}
			else if(a[i]<0)
			{
				whe1=false;
				whe2=false;
			}
		}
		if(whe2)
		{
			for(int i=1;i<=m-1;i++)
			{
				scanf("%d",&p);
			}
			scanf("%d",&p);
			for(int i=1;i<=n;i++)
			{
				if(v[i]>v0&&d[i]<p)
				{
					tot++;
				}
			}
			if(tot==0)
			{
				printf("%d %d\n",tot,m);
			}
			else
			{
				printf("%d %d\n",tot,m-1);
			}
		}
		else if(whe1)
		{
			for(int i=1;i<=m-1;i++)
			{
				scanf("%d",&p);
			}
			scanf("%d",&p);
			for(int i=1;i<=n;i++)
			{
				if(p>=d[i]&&v0*v0-v[i]*v[i]<2*a[i]*(p-d[i]))
				{
					tot++;
				}
			}
			if(tot==0)
			{
				printf("%d %d\n",tot,m);
			}
			else
			{
				printf("%d %d\n",tot,m-1);
			}
		}
		else
		{
			memset(whe,true,sizeof(whe));
			memset(lim,0,sizeof(lim));
			for(int i=1;i<=m;i++)
			{
				scanf("%d",&q[i]);
				for(int j=1;j<=n;j++)
				{
					if(q[i]>=d[j]&&(v0*v0-v[j]*v[j])<2*a[j]*(q[i]-d[j]))
					{
						whe[j]=false;
						lim[j][0]++;
						lim[j][lim[j][0]]=q[i];
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(!whe[i])
				{
					tot++;
					r[tot]=i;
				}
			}
//			for(int i=1;i<=tot;i++)
//			{
//				for(int j=1;j<=lim[r[i]][0];j++)
//				{
//					cout<<lim[r[i]][j]<<' ';
//				}
//				cout<<endl;
//			 } 
			memset(ad,0,sizeof(ad));
			cout<<tot<<' '<<m-dfs(1,0)<<endl;;
		}
	}
	return 0;
}

