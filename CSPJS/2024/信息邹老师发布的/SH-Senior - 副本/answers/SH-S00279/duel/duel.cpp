#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,m,a[N],p[N],cnt[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	p[1] = 1;
	cnt[1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(a[i] == a[i-1])
			p[i] = p[i-1];
		else
			p[i] = p[i-1] + 1;
		cnt[p[i]] ++;
	}
	m = p[n];
	for(int i=2;i<=m;i++)
	{
		cnt[i-1] = max(0,cnt[i-1] - cnt[i]);
		cnt[i] += cnt[i-1];
	}
	cout << cnt[m] << endl;
	return 0;
}
