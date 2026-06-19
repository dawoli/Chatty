#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
string p[1001];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int qwe=0;qwe<t;qwe++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		x--;
		y--;
		int ans=1;
		bool b[1001][1001];
		for(int i=0;i<n;i++){
			cin>>p[i];
			for(int j=0;j<m;j++){
				b[i][j]=false;
			}
		}
		b[x][y]=true;
		
		for(int i=0;i<k;i++){
			int xx,yy;
			if(d==0){
				xx=x;
				yy=y+1;
			}else if(d==1){
				xx=x+1;
				yy=y;
			}else if(d==2){
				xx=x;
				yy=y-1;
			}else if(d==3){
				xx=x-1;
				yy=y;
			}
			if(xx==n||xx==-1||yy==m||yy==-1){
				d=(d+1)%4;
			}else if(p[xx][yy]=='.'){
				x=xx;
				y=yy;
				if(b[x][y]==false){
					b[x][y]=true;
					ans++;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
