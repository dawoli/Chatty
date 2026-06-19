#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long MOD = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n, m;
	cin>>n>>m;
	string str;
	cin>>str;
	vector<int> a(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	if(cnt<m) {
		cout<<0<<endl;
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%MOD;
	cout<<ans<<endl; 
	return 0;
}
