#include<bits/stdc++.h>
using namespace std;
int n,m,len,maxv;
namespace s1
{
	const int N=3010;
	int sto[N],pos[N],a[N],v[N];
	int cnt[N];
	int ncnt[N][N];
	int nlen[N];
	void solve()
	{
		memset(cnt,0,sizeof(cnt));
		memset(ncnt,0,sizeof(ncnt));
		memset(nlen,0,sizeof(nlen));
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&pos[i],&v[i],&a[i]);
		} 
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&sto[i]);
		}
		sort(sto+1,sto+m+1);
		sto[0]=-1e9;
		sto[m+1]=1e9;
		int chao=0;
		for(int i=1;i<=n;i++)//inout car
		{
			int l,r;
			if(a[i]==0)//speed doesnot change
			{
				if(v[i]<=maxv)continue;//nchao
				else
				{
					l=pos[i],r=len;//chao
				}
			}
			else
			{
				if(v[i]<=maxv && a[i]<=0)continue;//nchao
				double ddis=(maxv*maxv-v[i]*v[i])/double(a[i]*2);
				//if(ddis<0)continue;
				//cout<<ddis<<endl;
				double fpos=min(ddis+pos[i],1.0*len);
				//cout<<fpos<<endl;
				if(a[i]>0)
				{
					l=ceil(fpos),r=len;
				}
				else
				{
					l=pos[i],r=floor(fpos);
				}
			}
			//cout<<i<<" "<<l<<" "<<r<<endl;
			for(int j=1;j<=m;j++)
			{
				if(sto[j]>=l && sto[j]<=r)
				{
					if(nlen[i]==0)chao++;
					cnt[j]++;
					ncnt[i][j]++;
					nlen[i]++;
				}
			}
		}
		int maxche=0;
		for(int i=1;i<=m;i++)
		{
			bool flag=1;
			for(int j=1;j<=n;j++)if(ncnt[j][i])if(nlen[j]==1)
			{
				flag=0;
				break;
			}
			if(flag==0)continue;
			maxche++;
			for(int j=1;j<=n;j++)if(ncnt[j][i])
			{
				nlen[j]--;
			}
		}
		printf("%d %d\n",chao,maxche);
	}
}
namespace s2
{
	void solve()
	{
		for(int i=1,t;i<=n;i++)
		{
			scanf("%d%d%d",&t,&t,&t);
		} 
		for(int i=1,t;i<=m;i++)
		{
			scanf("%d",&t);
		}
		printf("114514 114514\n");
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&len,&maxv);
		if(n<=3000)
		{
			s1::solve();
		}
		else
		{
			s2::solve();
		}
	}
	return 0;
}
