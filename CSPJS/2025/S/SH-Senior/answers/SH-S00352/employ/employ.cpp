#include<bits/stdc++.h>
using namespace std;
const int N=510;
void sync(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
}
int n,m,c[N];
char s[N];
int vis[N],sum[N],ans;
void dfs(int x,int cnt){
    //cout<<x<<" "<<cnt<<" ";
	if(cnt==m){
		ans++;
		return;
	} 
	if(x==n+1){
	//	for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
	//	cout<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			continue;
		}
		if(sum[i]<c[x] && s[i]=='1'){
			vis[i]=x;
			dfs(x+1,cnt+1);
			vis[i]=0;
		}
		else {
			vis[i]=x;
			dfs(x+1,cnt);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	sync();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sum[i]=sum[i-1]+(s[i]=='0'?1:0);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
