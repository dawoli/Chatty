#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int a[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	cout<<*max_element(a+1,a+N-9);
	return 0;
}

