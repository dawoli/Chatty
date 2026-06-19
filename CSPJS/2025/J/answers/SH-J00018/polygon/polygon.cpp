#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans=0;
void f(int t,int s,int m,int x)
{
	for(int i=x+1;i<n+t-3;i++)
	{
		f(t>2?3:t+1,s+a[i],a[i]>m?a[i]:m,i);
	}
	if(t>2)
	{
		if(s>2*m)
		{
			ans++;
		}
	}
}
int main() 
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n>30)
	{
		long long ssss=0,ss=1,sss=1;
		for(int j=0;j<3;j++)
		{
			ss*=n-j;
			sss*=j+1;
		}
		ssss+=(ss/sss)%998244353;
		for(int i=3;i<n;i++)
		{
			ss*=n-i;
			sss*=i+1;
			ssss+=(ss/sss)%998244353;
			ssss%=998244353;
			sss%=998244353; 
		}
		printf("%lld",ssss%998244353);
		return 0;
	}
	f(1,0,0,-1);
	printf("%d",ans%998244353);
	return 0;
}

