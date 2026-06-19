#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e3+5,mod=998244353;
int n,ma,ans,a[M];
int qp2(int x)
{
	if(x==0)return 1;
	if(x==1)return 2;
	return ((qp2(x/2))%mod*(qp2(x-x/2))%mod)%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	if(ma==1)
	{
		cout<<(qp2(n)-n*(n-1)/2-n-1+mod)%mod;
		return 0;
	}
	for(int i=3;i<=n;i++)
		for(int j=1;j<(1<<(i-1));j++)
		{
			int sum=0;
			for(int k=1,steps=1;k<=j;k*=2,steps++)
				if(j&(1<<(steps-1)))
					sum+=a[steps];
			if(sum>a[i])ans++;
		}
	cout<<ans;
	return 0;
}
