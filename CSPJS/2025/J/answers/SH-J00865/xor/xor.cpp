#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5,MAXM=1e6+1e5,MOD=0;
int n,k,a[MAXN+5],lst[MAXM+5],xor_sum,ans;
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
int main()
{
	init();
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(lst,-1,sizeof(lst));
	lst[0]=0;
	int t=0;
	for (int i=1;i<=n;i++)
	{
		xor_sum^=a[i];
		if (lst[xor_sum^k]>=t)
		{
			t=i;
			ans++;
		}
		lst[xor_sum]=i;
	}
	cout<<ans;
	return 0;
}
