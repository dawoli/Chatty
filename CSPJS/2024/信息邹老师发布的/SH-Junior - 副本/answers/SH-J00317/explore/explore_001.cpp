#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int t,n,m,k,x,y,d,ans=1;
char mapnm[1005][1005];
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mapnm[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl;;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int a=1;a<=t;a++){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				mapnm[i][j]=' ';
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mapnm[i][j];
			}
		}
		while(k--){
			mapnm[x][y]='O';
			if(d==0){
				if(mapnm[x][y+1]=='.'||mapnm[x][y+1]=='x'||mapnm[x][y+1]=='O'){
					if(mapnm[x][y+1]=='x'){
						d=(d+1)%4;
						continue;
					}else{
						y++;
						if(mapnm[x][y+1]=='.')
							ans++;
						continue;
					}
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(d==1){
				if(mapnm[x+1][y]=='.'||mapnm[x+1][y]=='x'||mapnm[x+1][y]=='O'){
					if(mapnm[x+1][y]=='x'){
						d=(d+1)%4;
						continue;
					}else{
						x++;
						if(mapnm[x+1][y]=='.')
							ans++;
						continue;
					}
				}else{
					d=(d+1)%4;
					continue;
				}
			}
			if(d==2){
				if(mapnm[x][y-1]=='.'||mapnm[x][y-1]=='x'||mapnm[x][y-1]=='O'){
					if(mapnm[x][y-1]=='x'){
						d=(d+1)%4;
						continue;
					}else{
						y--;
						if(mapnm[x][y-1]=='.')
							ans++;
						continue;
					}
				}else{
					d=(d+1)%4;
					continue;
				}		
			}
			if(d==3){
				if(mapnm[x-1][y]=='.'||mapnm[x-1][y]=='x'||mapnm[x-1][y]=='O'){
					if(mapnm[x-1][y]=='x'){
						d=(d+1)%4;
						continue;
					}else{
						x--;
						if(mapnm[x-1][y]=='.')
							ans++;
						continue;
					}
				}else{
					d=(d+1)%4;
					continue;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
