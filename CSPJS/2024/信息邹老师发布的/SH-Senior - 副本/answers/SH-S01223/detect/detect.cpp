#include <bits/stdc++.h>
#define int long long
using namespace std;
array<int,3> a[300000];
int p[300000];
vector<array<int,2> > res;
int sorting(array<int,2> x,array<int,2> y){
	return x[1] < y[1];
}
signed main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n,m,l,v;cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(a[i][2] == 0){
				if(a[i][1] > v && a[i][0] <= p[m]){
					ans ++;
					int pos = lower_bound(p+1,p+m+1,a[i][0]) - p;
					res.push_back({pos,m});
				}
			}
			else if(a[i][2] > 0){
				if(a[i][0] <= p[m] && p[m] * 2 * a[i][2] > v*v + 2*a[i][2]*a[i][0] - a[i][1]*a[i][1]){
					ans ++;
					int pos = upper_bound(p+1,p+m+1,(v*v+2*a[i][2]*a[i][0]-a[i][1]*a[i][1])/(2*a[i][2])) - p;
					res.push_back({pos,m});
				}
			}
			else{
				if(a[i][0] <= p[m]){
					int pos = lower_bound(p+1,p+m+1,a[i][0]) - p;
					if(a[i][1]*a[i][1] + 2*a[i][2]*(p[pos]-a[i][0]) > v*v){
						ans ++;
						int ps;
						int tmp = (v*v+2*a[i][2]*a[i][0]-a[i][1]*a[i][1]);
						if(tmp%(2*a[i][2])==0)ps = lower_bound(p+1,p+m+1,tmp/(2*a[i][2])) - p - 1;
						else ps = upper_bound(p+1,p+m+1,tmp/(2*a[i][2])) - p - 1;
						if(ps >= pos){
							res.push_back({pos,ps});
						}
					}
				}
			}
		}
		cout << ans <<' ';
		sort(res.begin(), res.end(), sorting);
		int sum = 0, ps = 0;
		for(int i=0;i<res.size();i++){
			if(res[i][0] > ps){
				ps = res[i][1];
				sum ++;
			}
		}
		cout << m-sum <<endl;
		res.clear();
	}
	return 0;
}
