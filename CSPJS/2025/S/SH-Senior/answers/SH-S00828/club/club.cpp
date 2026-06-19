#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3];
int dfs(int on,int tw,int th,int u) {
	if(u>n) return 0;
	int ans=0;
	if(on<n/2) ans=max(ans,dfs(on+1,tw,th,u+1)+a[u][1]);
	if(tw<n/2) ans=max(ans,dfs(on,tw+1,th,u+1)+a[u][2]);
	if(th<n/2) ans=max(ans,dfs(on,tw,th+1,u+1)+a[u][3]);
	return ans;
}
int main() {
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(0,0,0,1)<<endl;
	}
	return 0;
}
