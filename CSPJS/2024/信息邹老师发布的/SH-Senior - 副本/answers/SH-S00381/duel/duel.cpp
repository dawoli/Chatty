#include<bits/stdc++.h>
using namespace std;
int a[114514];
int n,x,maxx=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x;
		a[x]++;
		maxx = max(maxx,x);
	}
	int ans = a[1];
	for(int i=2;i<=maxx;i++){
		if(ans>a[i]) ans -= a[i];
		else ans = 0;
		ans += a[i];
	}
	cout << ans;
	return 0;
} 	
