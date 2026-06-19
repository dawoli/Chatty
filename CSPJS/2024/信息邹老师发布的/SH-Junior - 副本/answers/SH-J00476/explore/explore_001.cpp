#include<bits/stdc++.h>
using namespace std;
string s[1010];
int T,n,m,k,x,y,d;
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0}; 
bool in(int xx,int yy){
	if(xx<0||yy<0||xx>=n||yy>=m)	return false;
	else if(s[xx][yy]=='x')			return false;
	else							return true;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
		for(int i=0;i<n;++i)
			cin>>s[i];
		x--; y--;
		s[x][y]='Y';
		for(int i=1;i<=k;++i){
			if(in(x+dx[d],y+dy[d]))	x=x+dx[d],y=y+dy[d],s[x][y]='Y';
			else	d++,d%=4;	
		}
		int cnt=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(s[i][j]=='Y')
					++cnt;
		printf("%d\n",cnt);
	}
	return 0;
}
