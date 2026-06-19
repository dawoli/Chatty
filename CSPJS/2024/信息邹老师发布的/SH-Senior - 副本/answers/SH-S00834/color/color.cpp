#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N];
namespace BF{
	int lst[2],clr[N],ans;
	void dfs(int u){
		if(u==n+1){
			lst[0]=lst[1]=0; int tmp=0;
			for(int i=1;i<=n;i++){
				int u=lst[clr[i]];
				if(a[u]==a[i]) tmp+=a[i];
				lst[clr[i]]=i;
			}
//			for(int i=1;i<=n;i++) cout<<clr[i]<<' '; cout<<endl;
//			cout<<"---->"<<tmp<<endl;
			ans=max(ans,tmp);
			return;
		}
		clr[u]=1,dfs(u+1);
		clr[u]=0,dfs(u+1);
	}
	void solve(){
		ans=0; dfs(1);
		cout<<ans<<endl;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	for(int io=1;io<=T;io++){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		BF::solve();
	}
	return 0;
}
