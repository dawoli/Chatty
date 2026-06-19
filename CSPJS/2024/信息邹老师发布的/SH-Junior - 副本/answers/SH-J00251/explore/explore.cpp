#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int T,n,m,k,d;
char ch[N][N];
bool vst[N][N];
bool valid(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m&&ch[x][y]=='.')return 1;
	return 0;
}
void move(int&x,int&y){
	if(d==0)++y;
	if(d==1)++x;
	if(d==2)--y;
	if(d==3)--x;	
}
void Move(int&x,int&y){
	if(d==0)--y;
	if(d==1)--x;
	if(d==2)++y;
	if(d==3)++x;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int x,y;
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>ch[i][j];
		vst[x][y]=1;
		for(int i=1;i<=k;++i){
			move(x,y);
			if(valid(x,y))vst[x][y]=1;
			else{
				Move(x,y);
				d=(d+1)%4;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(vst[i][j]==1)++cnt;
		cout<<cnt<<'\n';
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				vst[i][j]=0;
	}
	return 0;
}
