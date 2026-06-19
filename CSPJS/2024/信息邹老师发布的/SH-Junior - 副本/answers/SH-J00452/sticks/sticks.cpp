#include<bits/stdc++.h>
using namespace std;
int t;
long long d[1001][1001];
int w[10]={6,2,5,5,4,5,6,3,7,6};
bool check(int a,int n)
{
	int sum=0;
	while(a!=0)
	{
		sum=sum+w[a%10];
		a=a/10;
		cout<<sum<<endl;
	}
	if(sum==n) return true;
	else
	 return false;
}
long long dp(int n)
{
	for(int i=1;i<=10;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j-w[i-1]>0)
				d[i][j]=max(d[i-1][j],d[i-1][j-w[i-1]]*10+i-1);
			else
				d[i][j]=d[i-1][j];
		}
	}
	for(int i=10;i>=1;i--)
	{
		for(int j=n;j>=0;j--)
		{
			if(check(d[i][j],n))
			{
				return d[i][j];
				break;
			}
		}
	}
	return -1;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			
			cout<<dp(n);
			
		}
	}
	return 0;
}
