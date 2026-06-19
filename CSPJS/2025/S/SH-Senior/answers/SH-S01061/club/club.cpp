#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][5],num[100005],ans[100005][5],cf[100005],maxn,ma=-1,ren[4];
bool cmp(long long a,long long b)
{
	if(a<b)
	{
		return false;
	}
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n==2)
		{
			int k=1;
			num[k++]=a[1][1]+a[2][2];
			num[k++]=a[1][1]+a[2][3];
			num[k++]=a[1][2]+a[2][1];
			num[k++]=a[1][2]+a[2][3];
			num[k++]=a[1][3]+a[2][1];
			num[k++]=a[1][3]+a[2][2];
			sort(num+1,num+k,cmp);
			cout<<num[1];
		}
		else
		{	
			for(int i=n;i>=1;i--)
			{
				int p;
				maxn=ans[i+1][1];
				for(int j=1;j<=3;j++)
				{
					ans[i][j]=a[i][j]+maxn;
					if(ans[i][j]>ma)
					{
						p=j;
						ma=ans[i][j];
					}
				}
				sort(ans[i]+1,ans[i]+n+1,cmp);
				cf[i]=ans[i][1]-ans[i][2];
				ma=-1;
				ren[p]++;
			}
			long long sum=ans[1][1];
			sort(cf+1,cf+n+1);
			for(int j=1;j<=3;j++)
			{
				if(ren[j]>n/2)
				{
					for(int m=1;m<=ren[j]-n/2;m++)
					{
						sum-=cf[m];
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
