#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=998244353;
ll n,R[10000],sum[10000],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>R[i];
	}
	sort(R+1,R+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=R[i]+sum[i-1];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			cout<<i<<" "<<j<<endl;
			if(sum[j]-sum[i]>2*R[j])
			{
				ans++;
			}
		}
		ans%=P;
	}
	ans%=P;
	cout<<ans;
	return 0;
}

