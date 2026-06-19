#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0}; 
char c[1009][1009];
set<pair<int,int> > s;
bool ok(){
	int nx=x+dx[d],ny=y+dy[d];
	if(nx>0&&nx<=n&&ny>0&&ny<=m&&c[nx][ny]=='.') return 1;
	return 0;
}
void go(){
	int nx=x+dx[d],ny=y+dy[d];
	x=nx,y=ny;
	s.insert(make_pair(x,y));
}
int main(){
	freopen("explore.in","r",stdin); 
	freopen("explore.out","w",stdout); 
	cin>>T;
	while(T--){
		s.clear();
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		s.insert(make_pair(x,y));
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=m;j++) cin>>c[i][j];
		for(int i=1;i<=k;i++){
			if(ok()){
				go();
			}
			else d=(d+1)%4;
		} 
		cout<<s.size()<<endl;
	}
	return 0;
} 
