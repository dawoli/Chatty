#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n;
int a[5005];
int sum;
int s[5005][10005];//前i个数和大于等于j的方案数
int t[5005][10005];//前i个数和等于j的方案数
int f[5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	sum-=a[n]+a[n-1];
	t[0][0]=1;
	for(int i=1;i<n-1;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			t[i][j]=t[i-1][j];
			if(j>=a[i])t[i][j]+=t[i-1][j-a[i]];
			t[i][j]%=MOD;
//			cout<<t[i][j]<<"\t";
		}
//		cout<<endl;
		for(int j=sum;j>=0;j--)
		{
			s[i][j]=t[i][j]+s[i][j+1];
			s[i][j]%=MOD;
//			cout<<s[i][j]<<"\t";
		}
//		cout<<endl;
	}
	for(int i=3;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=2;j<i;j++)
		{
			int x=a[i]-a[j]+1;
			f[i]+=s[j-1][x];
			f[i]%=MOD;
		}
//		cout<<f[i]<<endl;
	}
	cout<<f[n]<<endl;
	return 0;
}
