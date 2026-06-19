#include<bits/stdc++.h>
using namespace std;
const int N = 5009;
const int MOD = 998244353;
int l[N];
int n,ans;
vector<int> sel;
void dfs(int d,int sm,int mx,int m){
	if (d > n){
		if (m >= 3 && sm > 2 * mx) ans++; 
		return;
	}
	dfs(d+1,sm,mx,m);
	dfs(d+1,(sm+l[d]) % MOD,max(mx,l[d]),m+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++) cin>>l[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
