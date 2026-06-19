#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
const int N=1e5+10;
int n;
int a[N][3];
priority_queue<int> q[3];
inline void solve(){
	for(int i=0;i<=2;i++)
		while(!q[i].empty())
			q[i].pop();
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<pii> vec;
		for(int j=0;j<=2;j++)
			cin>>a[i][j],vec.push_back({a[i][j],j});
		sort(vec.begin(),vec.end());
		ans+=vec[2].first,q[vec[2].second].push(vec[1].first-vec[2].first);
	}
	for(int i=0;i<=2;i++)
		while(q[i].size()*2>n){
			ans+=q[i].top();
			q[i].pop();
		}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
