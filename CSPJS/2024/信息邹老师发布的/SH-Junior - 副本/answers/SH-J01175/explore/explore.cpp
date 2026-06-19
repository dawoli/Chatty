#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int m,n; 
int main(){
	int r,x,y,d;
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cnt=0;
		cin>>n>>m>>r;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		s[x][y]='z';
		for(int i=1;i<=r;i++){
			if(d==0&&s[x][y+1]!='x'&&x>=1&&x<=n&&y+1>=1&&y+1<=m){
				s[x][y+1]='z';
				y=y+1;
			}
			else if(d==1&&s[x+1][y]!='x'&&x+1>=1&&x+1<=n&&y>=1&&y<=m){
				s[x+1][y]='z';
				x=x+1;
			}
			else if(d==2&&s[x][y-1]!='x'&&x>=1&&x<=n&&y-1>=1&&y-1<=m){
				s[x][y-1]='z';
				y=y-1;
			}
			else if(d==3&&s[x-1][y]!='x'&&x-1>=1&&x-1<=n&&y>=1&&y<=m){
				s[x-1][y]='z';
				x=x-1;
			}
			else d=(d+1)%4;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) {
				if(s[i][j]=='z') cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 

