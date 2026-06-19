#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 2e5+10;
int n, q;
string s[N][2];
void solve(string t1, string t2){
	int ans = 0;
	for(int i=1; i<=n; ++i){
		if(s[i][0]
	}
}
int main(){
	freopen("replace1.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		int t1, t2;
		cin >> t1 >> t2;
		solve(t1, t2);
	}
	return 0;
}


