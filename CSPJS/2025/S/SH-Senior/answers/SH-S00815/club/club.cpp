#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int xh1,xh2,xh3;
	int ch1,ch2;
}NODE;
NODE arr[100005];
int chse[100005];
int sum1,sum2,sum3,n;
long long ans,ans1;
bool cmpA(node a,node b)
{
	return a.ch1<b.ch1;
}
void dfs(int layer,long long sum,int xh1,int xh2,int xh3)
{
	if(layer>n)
	{
		if(xh1<=(n/2)&&xh2<=(n/2)&&xh3<=(n/2))
		{
			ans1=max(ans1,sum);
			return ;
		}
		return ;
	}
	dfs(layer+1,sum+arr[layer].xh1,xh1+1,xh2,xh3);
	dfs(layer+1,sum+arr[layer].xh2,xh1,xh2+1,xh3);
	dfs(layer+1,sum+arr[layer].xh3,xh1,xh2,xh3+1);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		sum1=sum2=sum3=0;
		ans=ans1=0;
		int flagA=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&arr[i].xh1,&arr[i].xh2,&arr[i].xh3);
			if(arr[i].xh3!=0)
				flagA=0;
		}
		if(flagA)
		{
			for(int i=1;i<=n;i++)
			{
				if(arr[i].xh1>arr[i].xh2)
				{
					chse[i]=1;
					sum1++;
					ans+=arr[i].xh1;
				}
				else
				{
					chse[i]=2;
					sum2++;
					ans+=arr[i].xh2;
				}
				arr[i].ch1=abs(arr[i].xh1-arr[i].xh2);
			}
			if(sum1==(n/2))
			{
				printf("%d\n",ans);
				continue;
			} 
			else
			{
				sort(arr+1,arr+n+1,cmpA);
				if(sum1>sum2)
				{
					int i=1;
					while(sum1-(n/2)>0)
					{
						if(arr[i].xh1>=arr[i].xh2)
						{
							ans-=arr[i].ch1;
							sum1--;
							sum2++;
						}
						i++;
					}
				}
				else
				{
					int i=1; 
					while(sum2-(n/2)>0)
					{
						if(arr[i].xh2>=arr[i].xh1)
						{
							ans-=arr[i].ch1;
							sum2--;
							sum1++;
						}
						i++;
					}
				}
				printf("%lld\n",ans);
			}
		}
		else
		{
			dfs(1,0,0,0,0);
			printf("%lld\n",ans1);
		}
	}
	return 0;
}
