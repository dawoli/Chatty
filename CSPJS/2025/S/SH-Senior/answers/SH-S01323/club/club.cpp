#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
array<int,3> a[300000];
vector<int> x[3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		x[0].clear(); x[1].clear(); x[2].clear();
		int ans = 0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx= max(max(a[i][0], a[i][1]), a[i][2]);
			ans += mx;
			if(a[i][0] == mx)x[0].push_back(a[i][0] - max(a[i][1], a[i][2]));
			else if(a[i][1] == mx)x[1].push_back(a[i][1] - max(a[i][0], a[i][2]));
			else x[2].push_back(a[i][2] - max(a[i][0], a[i][1]));
		}
		for(int i=0;i<3;i++)sort(x[i].begin(), x[i].end());
		for(int i=0;i<3;i++){
			if(x[i].size() > n/2){
				for(int j=0;j<x[i].size()-n/2;j++) ans -= x[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
