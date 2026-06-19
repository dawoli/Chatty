#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,K_n;
int a_yuan[maxn];
int a[maxn];
int ask[maxn],KKK[maxn];
char xu[19][maxn];
int zheng[19][maxn];
long long sum[19][maxn];

void solve()
{
//	init...
	for (int j=1;j<=(1<<K_n);j++)	zheng[0][j]=j,sum[0][j]=j;
	for (int i=1;i<=K_n;i++)
	{
		for (int j=1;j<=(K_n>>i);j++)
		{
			if (xu[i][j]=='0')	zheng[i][j]=(a[zheng[i-1][j*2-1]]>=i ? zheng[i-1][j*2-1] : zheng[i-1][j*2]);
			else				zheng[i][j]=(a[zheng[i-1][j*2]]>=i ? zheng[i-1][j*2] : zheng[i-1][j*2-1]);
			sum[i][j]=sum[i-1][j*2-1]+sum[i-1][j*2];
		}
	}
	
	for (int q=1;q<=m;q++)
	{
		if (ask[q]==1)	{printf("1\n");continue;}
		if ((1<<KKK[q])==ask[q])	{printf("%d\n",zheng[KKK[q]][1]);continue;}
		vector<int> ding;ding.push_back(ask[q]);
		long long he=a[ask[q]];bool xin=0;
		for (int ceng=1,now=ask[q];ceng<=KKK[q]+1;ceng++,now>>=1)
		{
			if (xu[ceng][(now+1)>>1]=='0')
			{
				if (now&1)
				{
					bool flag=0;
					for (int i=0;i<ding.size();i++)
						if (ding[i]<ceng)
						{
							flag=1;
							he-=a[ding[i]];
							ding.erase(ding.begin()+i);
							i--;
						}
					if (xin||flag)
					{
						xin=1;
						he+=sum[ceng-1][now+1];
					}
				}
				else
				{
					bool flag=0;
					if (a[zheng[ceng-1][now-1]]>=ceng)
					{
						ding.clear();
						he=a[zheng[ceng-1][now-1]];
						ding.push_back(zheng[ceng-1][now-1]);
						xin=0;
					}
				}
			}
			else
			{
				if (now&1)
				{
					xin=1;
					he+=sum[ceng-1][now+1];
				}
				else
				{
					bool flag=0;
					for (int i=0;i<ding.size();i++)
						if (ding[i]<ceng)
						{
							flag=1;
							he-=a[ding[i]];
							ding.erase(ding.begin()+i);
							i--;
						}
					if (xin||flag)
					{
						xin=1;
						he+=sum[ceng-1][now-1];
					}
				}
			}
		}
		printf("%lld\n",he);
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)	scanf("%d",&a_yuan[i]);
	for (int i=1;i<=m;i++)	scanf("%d",&ask[i]);
	for (int i=1;i<=m;i++)
		while ((1<<KKK[i])<ask[i])	KKK[i]++;
	
	while ((1<<K_n)<n)		K_n++;
	for (int i=1;i<=K_n;i++)	scanf("%s",xu[i]+1);
	
	int T;scanf("%d",&T);
	int XXX[5];
	while (T--)
	{
		for (int i=0;i<4;i++)	scanf("%d",&XXX[i]);
		for (int i=1;i<=n;i++)	a[i]=a_yuan[i]^XXX[i%4];
		solve();
	}
	return 0;
}
