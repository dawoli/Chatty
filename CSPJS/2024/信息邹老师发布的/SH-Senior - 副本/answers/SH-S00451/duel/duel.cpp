#include <bits/stdc++.h>
using namespace std;
int n,a,ans,cnt[100009];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,cnt[a]++;
	for(int i=1;i<=100000;i++)ans=max(ans,cnt[i]);
	cout<<ans;
	return 0;
}
