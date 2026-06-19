#include<bits/stdc++.h>
using namespace std;
const int N=3009;
int a[N][N],n,m,k,cx,cy,cd,vst[N][N];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void solve(){
	memset(vst,0,sizeof vst);
	memset(a,0,sizeof a);
	cin>>n>>m>>k>>cx>>cy>>cd;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='x')a[i][j]=1;
		}
	}
	int res=0;
	k++;
	while(k--){
//		cout<<cx<<" "<<cy<<" "<<cd<<endl; 
		if(!vst[cx][cy])res++;
		vst[cx][cy]=1;
		int nx=cx+dx[cd],ny=cy+dy[cd];
		bool ok=1;
		if(nx<1||ny<1)ok=0;
		else if(nx>n||ny>m)ok=0;
		else if(a[nx][ny]==1)ok=0;
		else cx=nx,cy=ny;
		if(!ok)cd=(cd+1)%4;
	}
	cout<<res<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
