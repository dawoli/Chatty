#include<bits/stdc++.h>
using namespace std;
const int N=20,M=998244353;
int n,m,s[N],c[N]; 
long long ans=0;
bool vis[N];
void dfs(int d,int cnt,int tot){
	//cout<<d<<" "<<cnt<<" "<<tot<<'\n';
	if(d>n){
		if(tot>=m) ans++,ans%=M;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			//cout<<"i = "<<i<<'\n';
			if(cnt>=c[i]||s[d]==0) dfs(d+1,cnt+1,tot);
			else dfs(d+1,cnt,tot+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char p;cin>>p;
		s[i]=p-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
