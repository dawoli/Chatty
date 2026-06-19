#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],ans,del[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int j=2;
	for(int i=1;i<=n;i++)
	{
		while(j<=n&&a[j]==a[i]) j++;
		if(j<=n) del[i]=1;
		j++;
		if(j>n) break;
	}
	for(int i=1;i<=n;i++)
	{
		if(!del[i]) ans++;
	}
	cout<<ans;
	return 0;
}
