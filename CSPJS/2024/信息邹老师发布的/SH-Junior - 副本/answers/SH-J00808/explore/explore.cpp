#include<bits/stdc++.h>
using namespace std;
int t,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},x,y,d,n,m,k,b[1005][1005],sum;
char a[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		sum=0;
		x--;y--;
		for(int j=0;j<n;j++){
			cin>>a[j];
			for(int k=0;k<m;k++){
				b[j][k]=0;
			}
		}
		b[x][y]=1;
		while(k--){
			int xx=x+dx[d];
			int yy=y+dy[d];
			if(xx>=0&&xx<n&&yy>=0&&yy<m&&a[xx][yy]=='.'){
				b[xx][yy]=1;x=xx;y=yy;
			}
			else{
				d++;d%=4;
			}
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				sum+=b[j][k];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
