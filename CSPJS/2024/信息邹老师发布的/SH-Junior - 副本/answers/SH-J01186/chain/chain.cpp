#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l[100009],a,r,c;
struct num{
	int mx,dt,mn;
};
num b;
vector<num> s[100009];
void dfs(int x,int y,int mxx,int mnn,int cnt){
	if(cnt>10) return;
	for(int i=y+1;i<min(l[i],y+k);i++){
		s[x][i].mx=max(s[x][i].mx,mxx);
		s[x][i].mn=min(s[x][i].mn,mnn);
		for(int ii=1;ii<=n;ii++){
			for(int jj=0;jj<l[i];jj++){
				if(s[ii][jj].dt==s[x][i].dt&&(ii!=x||jj!=i)){
					dfs(ii,jj,max(s[ii][jj].mx,mxx+1),min(s[ii][jj].mn,mnn+1),cnt+1);
				}
			}
		}
	}
	return;
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<l[i];j++){
			if(s[i][j].dt==1){
				dfs(i,j,1,1,0);
			}
		}
	}
	return;
}
bool check(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<l[i];j++){
			if(s[i][j].dt==c&&s[i][j].mx>=r&&s[i][j].mn<=r){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int h=1;h<=T;h++){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>a;
				b.dt=a;
				b.mx=0;
				b.mn=1e9;
				s[i].push_back(b);
			}
		}
		solve();
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			if(check()) cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
