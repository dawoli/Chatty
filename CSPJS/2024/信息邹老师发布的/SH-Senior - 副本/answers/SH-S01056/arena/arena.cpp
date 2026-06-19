#include<bits/stdc++.h>
using namespace std;
int n,m;
int oa[100010],c[100010];
int pw2[20],K,up2[200000];
int d[20][200000];
int T;
int X[4];
int a[100010],id[100010];
int vc[200000];
int lowbit(int x)
{
	return x&(-x);
}
bool killed[100010];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&oa[i]);
	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
	pw2[0]=1;
	if(n!=1)
	{
		for(int i=1;i<=19;i++)
		{
			pw2[i]=pw2[i-1]*2;
			if(pw2[i]>=n)
			{
				K=i;
				break;
			}
		}
	}
	int last=0;
	up2[1]=0;
	for(int i=2;i<=n;i++)
	{
		up2[i]=last+1;
		if(i==pw2[last+1])last++;
	}
	for(int i=1;i<=K;i++)
	{
		for(int j=1;j<=pw2[K-i];j++)
		{
			char c;
			cin>>c;
			d[i][j]=c-'0';
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&X[0],&X[1],&X[2],&X[3]);
		for(int i=1;i<=n;i++)
		{
			a[i]=oa[i]^X[i%4];
			id[i]=i;
		}
		long long otp=0;
		for(int t=1;t<=m;t++)
		{
			memset(killed,0,sizeof(killed));
			for(int i=1;i<=up2[c[t]];i++)
			{
				for(int j=pw2[i];j<=c[t];j+=pw2[i])
				{
					int p1=j-pw2[i-1],p2=j;
					if(d[i][j/pw2[i]]==0)
					{
						if(a[p1]>=i)
						{
							killed[id[p2]]=1;
							id[j]=id[p1];
							a[j]=a[p1];
						}
						else
						{
							killed[id[p1]]=1;
							id[j]=id[p2];
							a[j]=a[p2];
						}
					}
					else
					{
						if(a[p2]>=i)
						{
							killed[id[p1]]=1;
							id[j]=id[p2];
							a[j]=a[p2];
						}
						else
						{
							killed[id[p2]]=1;
							id[j]=id[p1];
							a[j]=a[p1];
						}
					}
				}
			}
			for(int i=1;i<=c[t];i++)
			{
				if(killed[i]==0)
				{
					otp=otp^(t*i);
					break;
				}
			}
		}
		printf("%lld\n",otp);
	}
	return 0;
}
