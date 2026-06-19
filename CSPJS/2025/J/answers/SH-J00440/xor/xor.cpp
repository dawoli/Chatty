#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
typedef long long ll;
ll n,k,a[N],ans,vis[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			vis[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		ll t=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(vis[j]==1) break;
			t^=a[j];
			if(t==k)
			{
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

