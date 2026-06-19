#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
namespace BF{
	int out[N],atk[N],ans;
	bool chk(){
		for(int i=1;i<=n;i++)
			if(!out[i]&&!atk[i]) return 0;
		return 1;
	}
	void dfs(){
//		for(int i=1;i<=n;i++) cout<<out[i]<<" "; cout<<endl;
//		for(int i=1;i<=n;i++) cout<<atk[i]<<" "; cout<<endl;
//		cout<<"---->"<<chk()<<endl;
		if(chk()){
			int tmp=n;
			for(int i=1;i<=n;i++) tmp-=out[i];
			ans=min(ans,tmp); return;
		}
		for(int i=1;i<=n;i++)if(out[i]==0&&atk[i]==0)
			for(int j=1;j<=n;j++)if(out[j]==0&&j!=i){
//				cout<<i<<" atk "<<j<<endl; 
				atk[i]=1;
				if(a[i]>a[j]) out[j]=1;
				dfs();
				if(a[i]>a[j]) out[j]=0;
				atk[i]=0;
			}
	}
	void solve(){
		ans=n+1,dfs();
		cout<<ans<<endl;
	}
}
namespace STD{
	int cnt,ans;
	priority_queue<int,vector<int>,greater<int> >q;
	void solve(){
		ans=n;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(!q.empty()){
				if(q.top()<a[i]) q.pop(),ans--;}
			q.push(a[i]);
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
//	BF::solve();
	STD::solve();
	return 0;
}
