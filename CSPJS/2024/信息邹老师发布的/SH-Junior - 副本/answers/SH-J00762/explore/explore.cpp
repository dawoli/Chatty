#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d,cnt=1;
	char c[1010][1010];
	cin>>T;
	for (int q=1;q<=T;q++){
		cnt=0;n=0;m=0;k=0;x=0;y=0;d=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		for (int i=1;i<=k;i++){
			if (d%4==0){
				if (y+1<=m && c[x][y+1]=='.'){
					y+=1;
					cnt++;
					continue;
				} else{
					d+=1;
					continue;
				}
			} else if (d%4==1){
				if (x+1<=n && c[x+1][y]=='.'){
					x+=1;
					cnt++;
					continue;
				} else{
					d+=1;
					continue;
				}
			} else if (d%4==2){
				if (y-1>=1 && c[x][y-1]=='.'){
					y-=1;
					cnt++;
					continue;
				} else{
					d+=1;
					continue;
				}
			} else{
				if (x-1>=1 && c[x-1][y]=='.'){
					x-=1;
					cnt++;
					continue;
				} else{
					d+=1;
					continue;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
