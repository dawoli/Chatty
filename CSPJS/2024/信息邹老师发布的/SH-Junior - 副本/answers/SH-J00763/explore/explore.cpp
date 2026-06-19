#include<bits/stdc++.h>
using namespace std;
int mp[1005][1005];
int vis[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n,m,k,ans=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		x--;
		y--;
		string s;
		for(int j=0;j<n;j++){
			cin>>s;
			for(int l=0;l<m;l++){
				if(s[l]=='.'){
					mp[j][l]=0;
				}
				else{
					mp[j][l]=1;
				}
			}
		}
		vis[x][y]=1;
		for(int j=0;j<k;j++){
			int tx=x,ty=y;
			if(d==0){
				ty++;
			}
			else if(d==1){
				tx++;
			}
			else if(d==2){
				ty--;
			}
			else{
				tx--;
			}
			if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]==0){
				x=tx;
				y=ty;
				vis[x][y]=1;
			}
			else{
				d++;
				d%=4;
			}
		}
		for(int j=0;j<n;j++){
			for(int l=0;l<m;l++){
				if(vis[j][l]==1){
					ans++;
				}
				vis[j][l]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
