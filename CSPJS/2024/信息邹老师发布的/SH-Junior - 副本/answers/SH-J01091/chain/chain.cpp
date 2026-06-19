#include<bits/stdc++.h>
using namespace std;
int T,n,k,q,l;
struct abc{
	int x,y;
};
vector<abc> to[200500];
vector<int> a[100500];
void input(){
	memset(to,0,200000);
	memset(a,0,200000);
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=0;j<l;j++){
			int c;
			cin>>c;
			a[i].push_back(c);
			to[a[i][j]].push_back({i,j});
		}
	}
	return;
}
bool dfs(int u,abc t){
	if(u==1){
		for(int i=t.y-1;i>=max(t.y-k+1,0);i--)
			if(a[t.x][i]==1)
				return 1;
		return 0;
	}
	for(int i=t.y-1;i>=max(t.y-k+1,0);i--)
		for(int j=0;j<to[a[t.x][i]].size();j++)
			if(t.x!=to[a[t.x][i]][j].x && dfs(u-1,to[a[t.x][i]][j]))
				return 1;
	return 0;
}
void cul(){
	for(int i=1;i<=q;i++){
		int r,c,b=0;
		cin>>r>>c;
		for(int j=0;j<to[c].size();j++)
			if(dfs(r,to[c][j])){
				b=1;
				break;
			}
		cout<<b<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	for(int e=1;e<=T;e++){
		cin>>n>>k>>q;
		input();
		cul();
	}
	return 0;
} 
