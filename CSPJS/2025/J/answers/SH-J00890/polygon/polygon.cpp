#include <bits/stdc++.h>
using namespace std;	
const int N = 5e5 + 5;
#define int long long
int n,ans,a[N];

int f(int i,int j){
	int x = 0,maxx = 0;
	for(int k = i;k <= j;k++){
		x += a[k];
		maxx = max(maxx,a[k]);
	}
	if(x > 2 * maxx) return 1;
	return 0;
}

void solve(){
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	ans = f(1,3);
	cout<<ans;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
} 

