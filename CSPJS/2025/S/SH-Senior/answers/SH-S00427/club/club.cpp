#include<bits/stdc++.h>
using namespace std;
int T,n;
int cha[100001][4],a[100001][4],sum;
int ans[100001][4],cnt[4],c[100001][3],gai[100001][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])
			{
				cha[i][1]=1;
				cha[i][2]=2;
				cha[i][3]=3;
				c[i][1]=a[i][1]-a[i][2];
				c[i][2]=a[i][2]-a[i][3];
			}
			if(a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])
			{
				cha[i][1]=1;
				cha[i][2]=3;
				cha[i][3]=2;
				c[i][1]=a[i][1]-a[i][3];
				c[i][2]=a[i][3]-a[i][2];
			}
			if(a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])
			{
				cha[i][1]=2;
				cha[i][2]=1;
				cha[i][3]=3;
				c[i][1]=a[i][2]-a[i][1];
				c[i][2]=a[i][1]-a[i][3];
			}
			if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])
			{
				cha[i][1]=2;
				cha[i][2]=3;
				cha[i][3]=1;
				c[i][1]=a[i][2]-a[i][3];
				c[i][2]=a[i][3]-a[i][1];
			}
			if(a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])
			{
				cha[i][1]=3;
				cha[i][2]=1;
				cha[i][3]=2;
				c[i][1]=a[i][3]-a[i][1];
				c[i][2]=a[i][1]-a[i][2];
			}
			if(a[i][3]>=a[i][2]&&a[i][2]>=a[i][1])
			{
				cha[i][1]=3;
				cha[i][2]=2;
				cha[i][3]=1;
				c[i][1]=a[i][3]-a[i][2];
				c[i][2]=a[i][2]-a[i][1];
			}
		}
		for(int i=1;i<=n;i++)//先把最大值存入ans中 
		{
			cnt[cha[i][1]]++;
			gai[cnt[cha[i][1]]][cha[i][1]]=c[i][1];
			sum+=a[i][cha[i][1]];
		}
		int tot=0;
		if(cnt[1]>n/2) tot=1;
		else if(cnt[2]>n/2) tot=2;
		else if(cnt[3]>n/2) tot=3;
		int ci=cnt[tot];
		while(cnt[tot]>n/2)
		{
			int minn=100000;
			int g;
			for(int i=1;i<=ci;i++)
			{
				if(gai[i][tot]<=minn) minn=gai[i][tot],g=i;
			}
			sum=sum-minn;
			cnt[tot]--;
			gai[g][tot]=100001;
		}
		cout<<sum<<endl;
	} 
	return 0;
}

