#include<bits/stdc++.h>
using namespace std;
const int len=1e5+10;
int r[len];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0,tmp=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(r[i]>r[i-1])
		{
			tmp=i-1;
			continue;
		}
		if(i-tmp<=ans)
		{
			continue;
		}
		ans++;
	}
	cout<<ans;
	return 0;
}
