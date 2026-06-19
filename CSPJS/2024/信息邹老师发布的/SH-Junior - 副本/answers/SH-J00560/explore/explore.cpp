#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1010][1010];
bool book[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int cnt=1;
		memset(book,0,sizeof(book));
		cin>>n>>m>>k>>x>>y>>d;
		book[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(y+1<=m&&a[x][y+1]=='.'){
					if(book[x][y+1]==0) cnt++;
					book[x][y+1]=1;
					y++;
				}
				else d=(d+1)%4;
			} 
			else if(d==1){
				if(x+1<=n&&a[x+1][y]=='.'){
					if(book[x+1][y]==0) cnt++;
					book[x+1][y]=1;
					x++;
				}
				else d=(d+1)%4;
			} 
			else if(d==2){
				if(y-1>0&&a[x][y-1]=='.'){
					if(book[x][y-1]==0) cnt++;
					book[x][y-1]=1;
					y--;
				}
				else d=(d+1)%4;
			} 
			else if(d==3){
				if(x-1>0&&a[x-1][y]=='.'){
					if(book[x-1][y]==0) cnt++;
					book[x-1][y]=1;
					x--;
				}
				else d=(d+1)%4;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
