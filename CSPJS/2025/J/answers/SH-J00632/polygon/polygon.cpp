#include<bits/stdc++.h>
using namespace std;
long long ans=0;
bool q[5001];
int n,a[5001]={0};
void x(int t)
{
	int h=0,ma=0,s=0;
	if(t==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			if(q[i])
			{
				h+=a[i];
				ma=max(ma,a[i]);
				s++;
			}
		}
		if(h>2*ma && s>=3)
		{
		//	printf("%d %d %d %d %d\n",int(q[1]),int(q[2]),int(q[3]),int(q[4]),int(q[5]));
			ans++;
			ans%=998244353;
		}
	}
	else
	{
		
		q[t]=true;
		x(t+1);
		q[t]=false;
		x(t+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	x(1);
	printf("%d",ans);
	return 0;
}
/*
5
2 2 3 8 10
*/
/*
#include<bits/stdc++.h>
using namespace std;
int h[501][50001]={0};//i,size<j
long long ans=0;
bool ma[5001];
int n,a[5001]={0};
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma[a[i]]=true;
		for(int j=25;j>=1;j--)//50000
		{
			h[i][j]=h[i-1][j];
			if(j<=a[i] && j+a[i]<=50000)
			{
				h[i][j]=max(h[i][j],h[i-1][j+a[i]]*2+1);
			}
			printf("%d ",h[i][j]);
		}
		printf("\n");
	}
	
	for(int i=1;i<=5000;i++)
	{
		if(ma[i])
		{
			ans+=h[n][i];
		}
		
		
	}
	printf("%d",h[n][1]);
	return 0;
}*/
/*
5
2 2 3 8 10
*/
