#include<bits/stdc++.h>
#define INF 1e9
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	ll read(){
		ll x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-'){
				f=-1;
			}
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
char mp[6][1009][1009];
bool vst[6][1009][1009];
int T,m,n,x,y,d,k;
bool cango(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&(mp[T][x][y]=='.');
}
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	T=read();
	while(T--){
//		cout<<"Debug"<<endl;
		n=read(),m=read(),k=read();
		x=read(),y=read(),d=read();
		rep(i,1,n){
			rep(j,1,m){
				cin>>mp[T][i][j];
			}
		}
		vst[T][x][y]=1;
		while(k--){
			int nx=x+dx[d],ny=y+dy[d];
			if(cango(nx,ny)) x=nx,y=ny;
			else d=(d+1)%4;
			vst[T][x][y]=1;
		}
		int cnt=0;
		rep(i,1,n){
			rep(j,1,m){
				if(vst[T][i][j]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

