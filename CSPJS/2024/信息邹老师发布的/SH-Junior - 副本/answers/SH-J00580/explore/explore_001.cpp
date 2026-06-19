#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[1000][1000];
int T,n,m,k,d,x,y,ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=1;
		cin >>n>>m>>k>>x>>y>>d;
		x-=1,y-=1;
		a[x][y]=2;
		for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin>>a[i][j];
			if(a[i][j]=='x')a[i][j]=1;
			else a[i][j]=0;
		}

		while(k--){
			x+=dx[d],y+=dy[d];
			if(n>x&&x>-1&&m>y&&y>-1){
				if(!a[x][y])++ans,a[x][y]=2;
				else if(a[x][y]==1){
					t:x-=dx[d],y-=dy[d];
					d=(d+1)%4;
				}
			}
			else{
				goto t;
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
