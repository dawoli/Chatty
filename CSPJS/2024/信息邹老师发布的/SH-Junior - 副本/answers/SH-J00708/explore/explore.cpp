#include<bits/stdc++.h>
using namespace std;
char s[1009][1009];
bool ok[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=1;ii<=t;ii++){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
				ok[i][j]=0;
			}		
		}
		ok[x][y]=1;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(s[x][y+1]=='.'){
					y++;
					ok[x][y]=1;
				}else{
					d++;
				}
				continue;
			}
			if(d==1){
				if(s[x+1][y]=='.'){
					x++;
					ok[x][y]=1;
				}else{
					d++;
				}
				continue;
			}
			if(d==2){
				if(s[x][y-1]=='.'){
					y--;
					ok[x][y]=1;
				}else{
					d++;
				}
				continue;
			}
			if(d==3){
				if(s[x-1][y]=='.'){
					x--;
					ok[x][y]=1;
				}else{
					d=0;
				}
				continue;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(ok[i][j])
					ans++;
		cout<<ans<<"\n";
	} 
	return 0;
}
