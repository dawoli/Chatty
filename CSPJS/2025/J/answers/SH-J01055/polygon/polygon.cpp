#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],sum=0,r=0,quchu=0;
bool flag[10005]={};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	for(int i=0;i+3<=n;i++)
	{
		int t=1;
		for(int m=1;m<=n&&t<=i;m++)
		{
			if(flag[m]!=1)
			{
				quchu+=a[m];
				t++;
				flag[m]=1;
			}
		}
		int maxn;
		for(int g=n;g>=1;g--)
		{
			if(flag[g]==0)
			{
				maxn=a[g];
				break;
			}
		}
		if(sum-quchu>maxn*2)
		{
			r++;
			r%=998244353;
		}
		quchu=0;	
		for(int i=1;i<=n;i++)
		{
		flag[i]=0;
		}
	}
	cout<<r<<endl;
	return 0;
}
