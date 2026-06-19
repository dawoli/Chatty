#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x0,y0,d0;
char a[1005][1005];
set<pair<int,int> > st;
int nextpx(int x,int d){
	if(d==1) return x+1;
	if(d==3) return x-1;
	return x;
}
int nextpy(int y,int d){
	if(d==0) return y+1;
	if(d==2) return y-1;
	return y;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		st.clear();
		cin>>n>>m>>k>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>a[i][j];
		}
		int x=x0,y=y0,d=d0;
		st.insert({x,y});
		while(k--){
			int nx=nextpx(x,d);
			int ny=nextpy(y,d);
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='x'){
				x=nx,y=ny;
				st.insert({x,y});
			}else d=(d+1)%4;
		}
		cout<<st.size()<<endl;
	}
	return 0;
}
