#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool book[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book));
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		book[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(x>=1 && x<=n && y+1>=1 && y+1<=m && a[x][y+1]=='.'){
					y++;
					book[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==1){
				if(x+1>=1 && x+1<=n && y>=1 && y<=m && a[x+1][y]=='.'){
					x++;
					book[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else if(d==2){
				if(x>=1 && x<=n && y-1>=1 && y-1<=m && a[x][y-1]=='.'){
					y--;
					book[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
			else{
				if(x-1>=1 && x-1<=n && y>=1 && y<=m && a[x-1][y]=='.'){
					x--;
					book[x][y]=1;
				}
				else{
					d=(d+1)%4;
				}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(book[i][j]){
					s++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
