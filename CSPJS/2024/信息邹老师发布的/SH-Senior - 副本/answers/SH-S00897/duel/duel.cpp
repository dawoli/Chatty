#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,r[100005],cnt[100005],last;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&r[i]);
		cnt[r[i]]++;
	}
	for(int i=1;i<=100000;i++)
	{
		last-=min(last,cnt[i]);
		last+=cnt[i];
	}
	printf("%lld",last);
	return 0;
 } 
