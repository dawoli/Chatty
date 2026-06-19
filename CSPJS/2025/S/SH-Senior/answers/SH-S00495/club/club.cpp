#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005],c[100005];
int n;
int dfs(int aa,int bb,int cc,int sum,int i){
	if(aa > n/2) return sum-a[i-1];
	if(bb > n/2) return sum-b[i-1];
	if(cc > n/2) return sum-c[i-1]; 
	return max(dfs(aa+1,bb,cc,sum+a[i],i+1),max(dfs(aa,bb+1,cc,sum+b[i],i+1),dfs(aa,bb,cc+1,sum+c[i],i+1)));
}
void solve(){
	cin >> n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	if(n != 100000){
		cout << dfs(0,0,0,0,0) << "\n";
	}
	else{
		bool f1 = true,f2 = true;
		for(int i = 0;i < n;i++){
			if(b[i] != 0) f1 = false;
			if(c[i] != 0) f2 = false;
		}
		if(f1 and f2){
			int ans = 0;
			for(int i = 0;i < n;i++) ans += a[i];
			cout << ans << "\n";
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) solve();
}
