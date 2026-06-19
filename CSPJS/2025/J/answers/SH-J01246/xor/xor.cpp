#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 10;
vector <int> f[N];
int qian[N];
int n,k;
int a[N];
struct node
{
	int l, r;
};
bool cmp(node a,node b)
{
	if(a.l != b.l) return a.l < b.l;
	else return a.r < b.r;
}
vector <int> line[N];
int ans;
int dp[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	f[0].push_back(0);
	for(int t = 1;t <= n;t++)
	{
		scanf("%d",&a[t]);
		qian[t] = qian[t - 1] ^ a[t];
		if(!f[qian[t] ^ k].empty())
		{
			line[t].push_back(f[qian[t] ^ k].back() + 1);
		}
		f[qian[t]].push_back(t);
	}
	for(int t = 1;t <= n;t++)
	{
		dp[t] = dp[t - 1];
		if(!line[t].empty())dp[t] = max(dp[t],dp[line[t].back() - 1] + 1);
	}
	printf("%d",dp[n]); 
	return 0;
}
