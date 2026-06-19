#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int T; 
int n,m,k;
int x,y,d;
int cnt[9];
int w[N][N];
char p[N][N];
bool isAble(){
	if(d==0){
		if(x>=1&&x<=n&&y+1>=1&&y+1<=m&&p[x][y+1]!='x') return 1;
		else return 0;
	}else if(d==1){
		if(x+1>=1&&x+1<=n&&y>=1&&y<=m&&p[x+1][y]!='x') return 1;
		else return 0;
	}else if(d==2){
		if(x>=1&&x<=n&&y-1>=1&&y-1<=m&&p[x][y-1]!='x') return 1;
		else return 0;
	}else{
		if(x-1>=1&&x-1<=n&&y>=1&&y<=m&&p[x-1][y]!='x') return 1;
		else return 0;
	}
}
void avance(){
	if(d==0){
		y++;
	}else if(d==1){
		x++;
	}else if(d==2){
		y--;
	}else{
		x--;
	}
	w[x][y]=1;
}
void turn(){
	d=(d+1)%4;
}
void solve(int r){
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			w[i][j]=0;
		}
	}
	w[x][y]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(isAble()) avance();
		else turn();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(w[i][j]==1) cnt[r]++;
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		solve(l);
	}
	for(int l=1;l<=T;l++){
		cout<<cnt[l]<<endl;
	}
	return 0;
}


