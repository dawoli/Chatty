#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct chaf{
	int num,chaa;
} cha[N];
struct temp{
	int cl,manyi;
} tt[5];
int t,n,sum;
int arr[N][5];
int peo[N];
bool vis[N];
bool cmp(chaf a,chaf b)
{
	if(a.chaa==b.chaa)
	{
		return arr[a.num]>arr[b.num];
	}
	return a.chaa>b.chaa;
}
bool cmp2(temp a,temp b)
{
	return a.manyi>b.manyi;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(peo,0,sizeof peo);
		memset(vis,true,sizeof vis);
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>arr[i][j];
			}
		}
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cha[j].num=j;
				cha[j].chaa=arr[j][i]-arr[j][i+1];
			}
			sort(cha+1,cha+n+1,cmp);
			for(int j=1;j<=n;j++)
			{
				if(cha[j].chaa<=0)
				{
					break;
				}
				if(peo[i]==n/2)
				{
					break;
				}
				if(vis[cha[j].num])
				{
					peo[i]++;
					sum+=arr[cha[j].num][i];
					vis[cha[j].num]=false;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				for(int j=1;j<=3;j++)
				{
					tt[j].cl=j;
					tt[j].manyi=arr[i][j];
				}
				sort(tt+1,tt+4,cmp2);
				for(int j=1;j<=3;j++)
				{
					if(peo[tt[j].cl]<(n/2))
					{
						sum+=tt[j].manyi;
						peo[tt[j].cl]++;
						vis[i]=false;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
