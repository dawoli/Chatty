#include<bits/stdc++.h>
using namespace std;
const int N = 509;
int n,m,ans;
bool s[N],used[N];
int c[N];
const int MOD = 998244353; 
void dfs(int d,int cnt){
	if (d > n){
		if (cnt >= m) ans++;
		ans %= MOD;
		return;
	}
	for (int i = 1;i <= n;i++){
		if (used[i]) continue;
		used[i] = 1;
		if (s[d] && d-cnt <= c[i]){
			dfs(d+1,cnt+1);
		}else dfs(d+1,cnt);
		used[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		char ch;
		cin>>ch;
		if (ch == '1') s[i] = 1;
	}
	for (int i = 1;i <= n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
