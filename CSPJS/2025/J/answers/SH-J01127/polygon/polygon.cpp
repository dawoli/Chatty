#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iterator>
using namespace std;
const int max_n=5005;
int a[max_n];
int sum[1<<21],maxof[1<<21];
const int mod=998244353;
inline void mk(int n)
{
	for(int i=0;i<(1<<n+1);i++)
	{
		int c=i,pos=1;
		while(c)
		{
			if(c & 1)
				sum[i]+=a[pos],maxof[i]=max(maxof[i],a[pos]);
			c>>=1;
			pos+=1;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>a[i];
	}
	mk(n);
	long long ans=0;
	for(int i=0;i<(1<< n+1);i++)
		if(sum[i]>maxof[i]*2)
			ans+=1,ans%=mod;
	cout<<ans/2<<endl;
	return 0;
}
