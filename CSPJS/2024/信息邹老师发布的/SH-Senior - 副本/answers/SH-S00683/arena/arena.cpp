#include<bits/stdc++.h>
using namespace std;
const int N=19;
int T,n,m,a[N],b[N],c[N],tot,k;
bool d[1009][1009],vis[N];
void dfs(int x,int lim,vector<int> lst){
	if(lst.size()==1){
		if(!vis[lst[0]]){
			vis[lst[0]]=1;
			tot+=lst[0];
		}
		return;
	}
	int cnt=0;
	for(int j=0;j<lst.size()/2;j++){
		int now=d[x][j]?lst[j*2]:lst[j*2+1];
		if(now>lim) cnt++;
	}
	for(int p=0;p<(1<<cnt);p++){
		int cnt2=0;
		vector<int> nxt;
		for(int j=0;j<lst.size()/2;j++){
			int cs[2];
			cs[0]=lst[j*2],cs[1]=lst[j*2+1];
			int now=d[x][j]?0:1;
			if(cs[now]>lim){
				if(p&(1<<cnt2)) nxt.push_back(cs[0]);
				else nxt.push_back(cs[1]);
				cnt2++;
			}
			else{
				if(b[now]>=x) nxt.push_back(cs[now]);
				else nxt.push_back(cs[!now]);
			}
		}
		dfs(x+1,lim,nxt);
	}
}
void solve(){
	int ans=0;
	for(int i=1;i<=m;i++){
		tot=0;
		vector<int> init;
		for(int j=1;j<=(1<<k);j++) init.push_back(j);
		for(int j=1;j<=n;j++) vis[j]=0;
		dfs(1,c[i],init);
		ans^=(i*tot);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	k=ceil(log2(n));
	for(int i=1;i<=k;i++){
		string s;
		cin>>s;
		for(int j=0;j<(1<<k-i);j++) d[i][j]=(s[j]=='1');
	}
	cin>>T;
	while(T--){
		int x[4];
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=n;i++) b[i]=a[i]^x[i%4];
		solve();
	}
	return 0;
}
