#include <bits/stdc++.h>
using namespace std;
void sub(int n,int m,int k,int x,int y,int d){
	int tx,ty,cnt;
	string tmp;
	vector<vector<bool>> mp(n+2,vector<bool>(m+2,0));
	vector<vector<bool>> vis(n+2,vector<bool>(m+2,0));
	for(int c=1;c<=n;c++){
		cin>>tmp;
		for(int d=0;d<m;d++){ 
			if(tmp[d]=='x'){ 
				mp[c][d+1]=1;
			} 
		} 
	}
	for(int j=0;j<k+1;j++){
		vis[x][y]=1;
		if(d==0)tx=x,ty=y+1;
		if(d==1)tx=x+1,ty=y;
		if(d==2)tx=x,ty=y-1;
		if(d==3)tx=x-1,ty=y;
		if(1<=tx && tx<=n && 1<=ty && ty<=m && !mp[tx][ty])x=tx,y=ty;
		else d=(d+1)%4;
	}
	cnt=0;
	for(int c=1;c<=n;c++){
		for(int d=1;d<=m;d++){
			if(vis[c][d])cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	char tmp;
	int n,m,k,x,y,d,tx,ty,cnt;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m>>k>>x>>y>>d;
		sub(n,m,k,x,y,d);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
