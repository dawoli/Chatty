#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],x,m,ans,del[maxn],dp[maxn];
vector<int> v[maxn];
vector<pair<int,int> > q;
void dfs(int dep,int num) {
	if(dep==q.size()+1) {
		ans=max(ans,num);
		return ;
	}
	if(!del[dep]) {
		for(int i=0; i<q.size(); i++) {
			if(q[i].first<=q[dep].second||q[i].second>=q[dep].first) {
				del[i]=1;
			}
		}
		dfs(dep+1,num+1);
		for(int i=0; i<q.size(); i++) {
			if(q[i].first<=q[dep].second||q[i].second>=q[dep].first) {
				del[i]=0;
			}
		}
		dfs(dep+1,num);
	} else {
		dfs(dep+1,num);
	}
}
bool cmp(pair<int,int> a,pair<int,int> b) {
	return a.first<b.first;
}
bool check1() {
	for(int i=1; i<=n; i++) {
		if(a[i]!=1) {
			return false;
		}
	}
	return true;
}
void solve1() {
	cout<<n/2;
}
void solve2() {
	//dp i 看到了i，最多的区间数量
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int xors=i;
			for(int l=i+1; l<=j; l++) {
				xors^=l;
			}
			if(xors==k) {
				q.push_back({i,j});
			}
		}
	}
	sort(q.begin(),q.end(),cmp);
	dfs(1,0);//深度，区间数量
	cout<<ans;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	if(check1()) {
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		solve1();
	} else if(n<=100) {
		cin>>n>>k;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		solve2();
	} else {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>m;
			v[0].push_back(m);
		}
		while(x<n) {
			for(int i=0; i<v[x].size()-1; i++) {
				v[x+1].push_back(v[x][i]^v[x][i+1]);
			}
			x++;
		}
		for(int i=0; i<n; i++) {
			for(int j=n-i-1; j>=0; j--) {
				if(v[i][j]==k) {
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
