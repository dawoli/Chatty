#include<bits/stdc++.h>
using namespace std;

int n, a[200002], mx, ans;
bool st[200002];
vector<int> va, vb;
void dfs(int d){
	if(d > n){
		int sum = 0, j;
		for(int i = 1; i <= n; ++i){
			for(j = i - 1; st[j] != st[i] && j > 0; --j);
			if(a[j] == a[i])
				sum += a[i];
		}
		mx = max(sum, mx);
		return;
	}
	st[d] = true;
	dfs(d + 1);
	st[d] = false;
	dfs(d + 1);
}
void solve(){
	int res = 0;
	va = vector<int>();
	vb = vector<int>();
	for(int u : a){
		if(st[u])
			va.push_back(u);
		else
			vb.push_back(u);
	}
	for(int i = 0; i < va.size() - 1; ++i)
		if(va[i] == va[i + 1])
			res += va[i];
	for(int i = 0; i < vb.size() - 1; ++i)
		if(vb[i] == vb[i + 1])
			res += vb[i];
	ans = max(res, ans);
}
void pick(int i, int cur){
	if(cur > mx){
		if(i == 0)
			solve();
		return;
	}
	st[cur] = true;
	pick(i - 1, cur + 1);
	st[cur] = false;
	pick(i, cur + 1);
}
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		mx = 0;
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			mx = max(mx, a[i]); 
		}
		if(n <= 15){
			mx = 0;
			dfs(1);
			cout << mx << endl;
		}
		else{
			ans = 0;
			for(int i = 1; i <= mx / 2; ++i)
				pick(i, 1);
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//20·Ö±©Á¦ÊÔÊÔ°É

