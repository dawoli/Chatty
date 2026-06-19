#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=1e3+9;
char mp[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int T;
int n,m,k;
int x,y,d;
bool vst[N][N];
int ans;
void init(){
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
void print1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<vst[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
bool check(){
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(nx<1||nx>n){
		return 0;
	}
	if(ny<1||ny>m){
		return 0;
	}
	if(mp[nx][ny]=='x'){
		return 0;
	}
	return 1;
}
void Count(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vst[i][j]) ans++;
		}
	}
}
void solve(){
	memset(vst,0,sizeof(vst));
	init();
//	print();
//	cout<<"k="<<k<<endl;
	for(int i=1;i<=k;i++){
		vst[x][y]=1;
		if(check()){
			x+=dx[d];
			y+=dy[d];
			vst[x][y]=1;
//			cout<<"Go to ("<<x<<','<<y<<")\n";
		}
		else{
			d=(d+1)%4;
//			cout<<"Turn to "<<d<<'\n';
		}
	}
	Count();
	cout<<ans<<endl;
//	print1();
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		solve();
	}
	return 0;
}
