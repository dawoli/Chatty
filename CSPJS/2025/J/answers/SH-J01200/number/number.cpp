#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
priority_queue<int> pq;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("number.out","w",stdout);//Don't forgrt freopen(stdout)
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1;i <= n;i++){
		if('0' <= s[i] && s[i] <= '9')
			pq.push(s[i] - '0');
	}
	while(pq.size()){
		cout << pq.top();
		pq.pop();
	}
	return 0;
}

