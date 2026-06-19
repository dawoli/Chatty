#include <bits/stdc++.h>
using namespace std;
int a[5000];int pl[5000];int n;int sd1,sd2;int ans;
void dfs(int d)
{
	if(d>sd1)
	{
		int temp=0,maxn=-1;
		for(int i=1;i<=sd1;i++)
		{
			temp+=a[pl[i]];
			maxn=max(maxn,a[pl[i]]);
		}
		if (temp > 2*maxn){ans++;
		return; }
	}
	for(int i=pl[d-1]+1;i<=sd2;i++)
	{
		pl[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	sd2=n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=3;i<=n;i++)
	{
		sd1=i;
		dfs(1);
	}
	cout << ans;
	return 0;
 } 
