#include <bits/stdc++.h>
using namespace std;

int a[100005],p[100005],r,cnt=0,n;

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[a[i]]++;
	}
	for(int i = 1; i <= 1e5; i++)
	{
		cnt += min(r,p[i]);
		r = max(0,r-p[i]);
		r+=p[i];
	}
	cout << n-cnt;
	
}
