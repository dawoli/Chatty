#include <bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,a[5005];
int op(int p,int q)
{
	long long ans=1;
	for(int i=p-q;i<=p;i++)
	{
		ans*=i;
		ans%=M;
	}
	long long tem=1;
	for(int i=1;i<=q;i++)
	{
		tem*=i;
		tem%=M;
	}
	ans/=tem;
	ans%=M;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	
	if(n==3)
	{
		int maxn=0,sum=0;
		for(int i=1;i<=3;i++)
		{
			if(a[i]>maxn) maxn=a[i];
			sum+=a[i];
		}
		if(maxn*2<sum) cout << 1;
		else cout << 0;
		return 0;
	}
	int maxn=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxn) maxn=a[i];
		sum+=a[i];
	}
	int ans=0;
	if(maxn==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=op(n,i);
			ans%=M;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
