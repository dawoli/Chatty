#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;vector<int> a[200005];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < 200005; i++){
			a[i].clear();
		}
		for(int i = 0; i < n; i++){
			int b;
			cin >> b;
			a[b].push_back(i);
		}
		int ans = 0;
		for(int i = 1; i < 200005; i++){
			ans += (a[i].size()/2) * i;
		}
		cout << ans;
	}
	
	return 0;
} 
