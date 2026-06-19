#include<bits/stdc++.h>

using namespace std;
int n,m,a[105],cnt,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) cin >> a[i];
	for(int i=2; i<=n*m; i++) if(a[i]>a[1]) cnt++;
	ans1=cnt/n+1;
	if(ans1%2) ans2=cnt%m+1;
	else ans2=n-cnt%m;
	cout << ans1 << " " << ans2;
	return 0;
}
