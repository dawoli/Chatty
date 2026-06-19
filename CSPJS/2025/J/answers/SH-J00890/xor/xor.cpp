#include <bits/stdc++.h>
using namespace std;	
const int N = 5e5 + 5;
#define int long long
int n,k,a[N];
vector<int> b[N];

int dfs(int x,int cnt){
	int ans  = 0;
	if(x >= n) return cnt - 1;
	while(b[x].empty()){
		x++;
		if(x >= n) return cnt - 1;
	}
	for(auto i : b[x]) ans = max(ans,dfs(i + 1,cnt + 1));
	return ans;
}

void solve(){
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int x = a[i];
			if(i == j) x = a[i]; 
			for(int k2 = i + 1;k2 <= j;k2++){
				x = (x ^ a[k2]);
			}
			if(x == k) b[i].push_back(j);
		} 
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) ans = max(ans,dfs(i,1));
	
	cout<<ans;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
} 
