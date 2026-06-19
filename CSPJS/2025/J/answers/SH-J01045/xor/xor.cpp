#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e6+5;
int n,k,now=1,ans,a[M],xs[M];
vector<int>ks[M];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xs[i]=xs[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)ks[xs[i]].push_back(i);
	while(now<=n)
	{
		int l=0,r=ks[xs[now-1]^k].size();
		while(l<r)
		{
			int mid=(l+r)/2;
			if(ks[xs[now-1]^k][mid]<now)l=mid+1;
			else r=mid;
		}
		if(ks[xs[now-1]^k][l]>=now)now=ks[xs[now-1]^k][l]+1,ans++;
		else now++;
	}
	cout<<ans;
	return 0;
} 
