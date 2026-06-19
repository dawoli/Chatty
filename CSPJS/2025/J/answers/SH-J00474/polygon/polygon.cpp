#include<bits/stdc++.h>
using namespace std;
int dp[1000090];
int n;
int a[1000090];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int sum=0;
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int c=1;c<=n;c++)
			{
				sum++;
			}
			sum=sum-i;
		}		
	}
	cout<<sum;
	return 0;
}
