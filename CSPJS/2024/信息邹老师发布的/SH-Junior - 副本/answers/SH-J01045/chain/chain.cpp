#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9,M=2e3+9;
int a[M][N],t[N],n,k,q,x,y,T;
bool vis=0;
void dfs(int rx,int p,int ry){
	if (rx==0) vis=0;
	if (rx==x){
		if (ry==y){
			vis=1;
			return;
		}
		else return;
	}
	else if (rx==0 and vis==0 and p==0){
		for (int o=1;o<=n;o++){
			for (int j=1;j<=a[o][0] and vis==0;j++){
				if (ry!=a[o][j]) continue;
				for (int l=j+1;l<=a[o][0] and l-j+1<=k and vis==0;l++){
					dfs(1,o,a[o][l]);
				}
			}
		}
	}
	else if (vis==0){
		for (int o=1;o<=n;o++){
			if (o==p) continue;
			for (int j=1;j<=a[o][0] and vis==0;j++){
				if (ry!=a[o][j]) continue;
				for (int l=j+1;l<=a[o][0] and l-j+1<=k and vis==0;l++){
					dfs(rx+1,o,a[o][l]);
				}
			}
		}
	}
	if (rx==0){
		cout<<vis<<endl;
	}
	return;
}
void solve(){
	bool vis=0;
	dfs(0,0,1);
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++){
		vis=0;
		cin>>n>>k>>q;
		for (int i=1;i<=n;i++){
			cin>>a[i][0];
			for (int j=1;j<=a[i][0];j++){
				cin>>a[i][j];
				t[a[i][j]]++;
			}
		}
		for (int i=1;i<=q;i++){
			cin>>x>>y;
			if (t[1]==0 or t[y]==0) cout<<0<<endl;
			else solve();
		}
	}
	return 0;
}
