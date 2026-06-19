#include<bits/stdc++.h>
using namespace std;
//#define int long long

priority_queue<int> pq;

void solve(){
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			pq.push(s[i] - '0');
		}
	}
	while(pq.size()){
		cout << pq.top();
		pq.pop();
	}
}

signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t = 1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
