#include<iostream>
using namespace std;
int t,n,m,k,x,y,d;
char map[1005][1005];
bool t[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		int sum=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
			}
		}
			if(d==0){
				if(y+1<=m and map[x][y+1]!='x'){
					y++;
				}else{
					d=1;
				}
			}else if(d==1){
				if(x+1<=n and map[x+1][y]!='x'){
					x++;
				}else{
					d=2;
				}
			}else if(d==2){
				if(y-1>=1 and map[x][y-1]!='x'){
					y--;
				}else{
					d=3;
				}
			}else if(d==3){
				if(x-1>=1 and map[x-1][y]!='x'){
					x--;
				}else{
					d=0;
				}
			}
			k--;
		while(k--){
			if(d==0){
				if(y+1<=m and map[x][y+1]!='x'){
					y++;
					if(t[x][y]!=1){
						t[x][y]=1;
						sum++;
					}
					continue;
				}else{
					d=1;
					continue;
				}
			}else if(d==1){
				if(x+1<=n and map[x+1][y]!='x'){
					x++;
					if(t[x][y]!=1){
						t[x][y]=1;
						sum++;
					}
					continue;
				}else{
					d=2;
					continue;
				}
			}else if(d==2){
				if(y-1>=1 and map[x][y-1]!='x'){
					y--;
					if(t[x][y]!=1){
						t[x][y]=1;
						sum++;
					}
					continue;
				}else{
					d=3;
					continue;
				}
			}else if(d==3){
				if(x-1>=1 and map[x-1][y]!='x'){
					x--;
					if(t[x][y]!=1){
						t[x][y]=1;
						sum++;
					}
					continue;
				}else{
					d=0;
					continue;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
