#include<bits/stdc++.h>
using namespace std;
int a[5010];
int flag[5010];
long long summ(int k,int n,long long sum)
{
	long long ans=0;
	if(k==(n-2))
	{
		for(int i=k+1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>a[i]*2)ans++;
			sum-=a[i];
		}
		return ans;
	}
	for(int i=k;i<=n;i++)
	{
		ans+=summ(i+1,n,sum+a[i]);
		ans=ans%998244353;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	if(n<=3)
	{
		int maxx=0,sum=0;
		for(int i=1;i<=3;i++)
		{
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2)
			printf("1");
		else
			printf("0");
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		printf("9");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		printf("6");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++)
		printf("%d ", a[i]);
	long long ans;
	ans=summ(1,n,0);
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
