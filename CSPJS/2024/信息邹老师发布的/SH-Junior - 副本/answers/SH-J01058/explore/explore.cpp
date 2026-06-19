#include<bits/stdc++.h>
using namespace std;
int sx[10]={0,1,0,-1};
int sy[10]={1,0,-1,0};
int g[1009][1009],vst[1009][1009];
int n,m,k,x,y,d,cnt=0;
void move(){
	if(g[x+sx[d]][y+sy[d]]==0&&0<x+sx[d]&&x+sx[d]<=n&&0<y+sy[d]&&y+sy[d]<=m){
	 	x+=sx[d];
	 	y+=sy[d];
	 	if(vst[x][y]==0){
	 		vst[x][y]=1;
	 		cnt++;
		}
	}
	else d=(d+1)%4;
}
void solve(){
	cnt=1;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		char s;
		cin>>s;
		if(s=='x')g[i][j]=1;
		if(s=='.')g[i][j]=0;
		vst[i][j]=0;
	}
	vst[x][y]=1;
	for(int i=1;i<=k;i++)move();
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout); 
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
