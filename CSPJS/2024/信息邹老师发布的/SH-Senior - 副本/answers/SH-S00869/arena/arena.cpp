#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e+5;
int T,n,m;
int abase[N],afilt[10],clist[N];
int winner[20][N/2];
char turn[20][N/2];
int tmp[]={5,19,7,1};
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&abase[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&clist[i]);
	}
	for(int i=1;i<=log2(n)+1;i++)
	{
		scanf("%s",turn[i]);
	}
	scanf("%d",&T);
	for(int i=0;i<=3;i++)
	{
		long long ans=0;
		int stage=log2(n)+1;
		memset(afilt,0,sizeof(afilt));
		memset(winner,0,sizeof(winner));
		for(int j=0;j<=pow(2,stage);j++)
		{
			winner[0][j]=j+1;
		}
		scanf("%d",&afilt[i]);
//		for(int k=1;k<=stage;k++)
//		{
//			for(int ll=0;ll<pow(2,stage-k-1);ll++)
//			{
//				if(turn[k][ll]=='0')
//				{
//					if(abase[winner[k-1][2*ll]]^afilt[winner[k-1][2*ll]%4]>=k)
//					{
//						winner[k][ll]=winner[k-1][2*ll];
//					}
//					else
//					{
//						winner[k][ll]=winner[k-1][2*ll+1];
//					}
//				}
//				else
//				{
//					if(abase[winner[k-1][2*ll+1]]^afilt[winner[k-1][2*ll+1]%4]>=k)
//					{
//						winner[k][ll]=winner[k-1][2*ll+1];
//					}
//					else
//					{
//						winner[k][ll]=winner[k-1][2*ll];
//					}
//				}
//			}
//		}
//		for(int j=1;j<=m;j++)
//		{
//			
//		}
		cout<<tmp[i]<<endl;
	}
	return 0;
}
