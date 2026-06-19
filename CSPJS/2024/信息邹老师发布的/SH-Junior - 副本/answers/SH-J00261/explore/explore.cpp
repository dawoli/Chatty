#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		char mp[1009][1009];
	for(int i=0;i<=1006;i++)
		for(int j=0;j<=1006;j++)
			mp[i][j]='#';
	int n,m,k;
	int sx,sy,sd;
	int nx,ny,cnt,d;
	cin>>n>>m>>k;
	cin>>sx>>sy>>sd;
	nx=sx;
	ny=sy;
	d=sd;
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	mp[sx][sy]='Y';
	for(int i=1;i<=k;i++){
		char nxt;
		if(d==0)
			nxt=mp[nx][ny+1];
		else if(d==1)
			nxt=mp[nx+1][ny];
		else if(d==2)
			nxt=mp[nx][ny-1];
		else nxt=mp[nx-1][ny];
		if(nxt=='#'||nxt=='x')
			d=(d+1)%4;
		if(nxt=='.'||nxt=='Y'){
			if(d==0)
				ny++;
			else if(d==1)
				nx++;
			else if(d==2)
				ny--;
			else nx--;
			if(nxt=='.')
				mp[nx][ny]='Y';
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(mp[i][j]=='Y')
					cnt++;
		cout<<cnt<<endl;
	}
		
	return 0;
}
