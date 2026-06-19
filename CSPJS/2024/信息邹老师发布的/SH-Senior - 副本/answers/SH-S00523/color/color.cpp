#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll T,n,c[N];
int red[N],re,blu[N],bl;
ll ans;
void dfs(int nw,ll nwans){
	if(nw>n){
		ans=max(ans,nwans);
		return;
	}
	red[++re]=c[nw];
	dfs(nw+1,nwans+(red[re]==red[re-1]?red[re]:0));
	red[re--]=0;
	blu[++bl]=c[nw];
	dfs(nw+1,nwans+(blu[bl]==blu[bl-1]?blu[bl]:0));
	blu[bl--]=0;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>c[i];
		dfs(1,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
