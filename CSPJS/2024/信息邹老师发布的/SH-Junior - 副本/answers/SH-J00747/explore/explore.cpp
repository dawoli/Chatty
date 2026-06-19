#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
char b[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int t,n,m,k,x,y,d;cin>>t;
	while(t--){
		int c=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>b[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=0;
			}
		}
		while(k--){
		a[x][y]=1;
			if(d==0){
				if(y+1<=m){
					if(b[x][y+1]=='.') {
						y++;
					}
					else{
						d+=1;
					}
				}
				else{
					d+=1;
				}
			}
			else if(d==1){
				if(x+1<=n){
					if(b[x+1][y]=='.') {
						x++;
					}
					else{
						d+=1;
					}
				}
				else{
					d+=1;
				}
			}
			else if(d==2){
				if(y-1>=1){
					if(b[x][y-1]=='.') {
						y--;
					}
					else{
						d+=1;
					}
				}
				else{
					d+=1;
				}
			}
			else if(d==3){
				if(x-1>=1){
					if(b[x-1][y]=='.') {
						x--;
					}
					else{
						d=0;
					}
				}
				else{
					d=0;
				}
			}
			a[x][y]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1){
					c++;
				}
			}
		}
		cout<<c<<endl;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
