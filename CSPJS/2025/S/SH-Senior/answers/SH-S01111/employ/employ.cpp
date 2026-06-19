#include<bits/stdc++.h>
using namespace std;
const int N = 505;

int n, m, c[N];
string s;
int a[N], ans;
bool vis[N];

void dfs(int k, int unable){
	if(k > n){
//		for(int i=1; i<=n; i++){
//			cout<<a[i]<<" \n"[i==n];
//		} cout<<unable<<endl;
		if(unable <= n-m) ans++;
		return;
	}
	
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		a[k] = c[i];
		vis[i] = true;
		
		
		if(unable >= c[i] || s[k] == '0'){
			dfs(k+1, unable+1);
		} else {
			dfs(k+1, unable);
		}
		
		vis[i] = false;
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s; s = " " + s;
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	dfs(1, 0);
	cout<<ans;
	return 0;
}

