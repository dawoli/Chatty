#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,cnt,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1009][1009];bool vst[1000009];
int T;
bool vaild(int prex,int prey){
	return 1<=prex&&prex<=n&&1<=prey&&prey<=m&&a[prex][prey]=='.';
}
void upd(int x,int y){
	int pos=(x-1)*m+y;
	if (!vst[pos]) vst[pos]=true,++cnt;
}
void move(){
	int nx=x+dx[d],ny=y+dy[d];
	if (vaild(nx,ny)) x=nx,y=ny;
	else d=(d+1)%4;
	upd(x,y);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for (int q=1;q<=T;++q){
		fill(vst,vst+1000009,false);
		cnt=0;cin>>n>>m>>k>>x>>y>>d;upd(x,y);
		for (int i=1;i<=n;++i) for (int j=1;j<=m;++j) cin>>a[i][j];
		for (int i=1;i<=k;++i){
			move();
		}
		printf("%d\n",cnt);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
