#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,k,x,y,d,ans=0;
	char mp[1005][1005];
	bool is[1005][1005]={0};
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	is[x][y]=true;
	for(int i=1;i<=k;i++){
		if(d==0){
			if(x<1||y+1<1||x>n||y+1>m||mp[x][y+1]!='.'){
				d=(d+1)%4;
			}
			else{
				y++;
				is[x][y]==1;
			}
		}
		else if(d==1){
			if(x+1<1||y<1||x+1>n||y>m||mp[x+1][y]!='.'){
				d=(d+1)%4;
			}
			else{
				x++;
				is[x][y]==1;
			}
		}
		else if(d==2){
			if(x<1||y-1<1||x>n||y-1>m||mp[x][y-1]!='.'){
				d=(d+1)%4;
			}
			else{
				y--;
				is[x][y]==1;
			}
		}
		else if(d==3){
			if(x-1<1||y<1||x-1>n||y>m||mp[x-1][y]!='.'){
				d=(d+1)%4;
			}
			else{
				x--;
				is[x][y]==1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<is[i][j];
			if(is[i][j])ans++;
		}
		cout<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
}
