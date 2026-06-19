#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
bool check(vector<int> b){
	if(b.size()<3) return false;
	long long sum=0;
	for(int i=0;i<b.size();i++) sum+=b[i];
	if(sum<=b[b.size()-1]*2) return false;
	return true;
}
void dfs(int dep,vector<int> a,vector<int> b){
	if(dep>=n){
		if(check(b)) ans++;
		return;
	}
	dfs(dep+1,a,b);
	b.push_back(a[dep]);
	dfs(dep+1,a,b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	vector<int> a(n),b;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	dfs(0,a,b);
	cout<<ans<<"\n";
	return 0;
}

