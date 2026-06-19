#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x0,y0,d0;
char a[1010][1010];
int vst[1010][1010];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				vst[j][k]=0;
			}
		}
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>a[j][k];
			}
		}
		int x=x0,y=y0,d=d0;
		for(int j=1;j<=k;j++){
			int xt=x,yt=y;
			if(d==0){
				y++;
			}else if(d==1){
				x++;
			}else if(d==2){
				y--;
			}else if(d==3){
				x--;
			}
			if(x<1||y<1||x>n||y>m||a[x][y]=='x'){
				d=(d+1)%4;
				x=xt;
				y=yt;
				continue;
			}else{
				vst[x][y]=1;
			}
		}
		int cnt=0;
		vst[x0][y0]=1;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(vst[j][k]==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
