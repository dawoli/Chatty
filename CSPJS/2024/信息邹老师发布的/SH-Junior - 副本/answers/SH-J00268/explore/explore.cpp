#include<bits/stdc++.h>
using namespace std;
int t;
int a[1010][1010];
int b[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,dt;
		cin>>x>>y>>dt;
		for(int i=1;i<=n;i++){
			char ch[1005];
			cin>>ch;
			for(int j=0;j<m;j++){
				if(ch[j]=='.') a[i][j+1]=1;
				else if(ch[j]=='x') a[i][j+1]=0;
			}
		}
		memset(b,0,sizeof(b));
		b[x][y]=1;
		while(k--){
			int xn=0,yn=0;
			if(dt==0){
				xn=x,yn=y+1;
			}else if(dt==1){
				xn=x+1,yn=y;
			}else if(dt==2){
				xn=x,yn=y-1;
			}else{
				xn=x-1,yn=y;
			}
			if(a[xn][yn]==0||xn>n||yn>m||xn<0||yn<0){
				dt=(dt+1)%4;
			}else{
				x=xn,y=yn;
				b[x][y]=1;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i][j]==1) cnt++;
			}
		} 	
		cout<<cnt<<"\n";
	}
	return 0;
}
