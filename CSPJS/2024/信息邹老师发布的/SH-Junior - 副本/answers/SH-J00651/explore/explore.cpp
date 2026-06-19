#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,ans,x0,y0,d0;
bool f[1001][1001];
char a[1001][1001];
bool pf(int x,int y){
	if(x<1||x>n||y<1||y>m||a[x][y]=='x') return false;
	return true;
}
int fx(int d,int x){
	int x1;
	if(d==0) x1=x;
	if(d==1) x1=x+1;
	if(d==2) x1=x;
	if(d==3) x1=x-1;
	return x1;
}
int fy(int d,int y){
	int y1;
	if(d==0) y1=y+1;
	if(d==1) y1=y;
	if(d==2) y1=y-1;
	if(d==3) y1=y;
	return y1;
}
int dfs(int x,int y,int d){
	int x1,y1,d1;
	if(!f[x][y]) ans++;
	f[x][y]=true;
	if(d==0) x1=x,y1=y+1;
	if(d==1) x1=x+1,y1=y;
	if(d==2) x1=x,y1=y-1;
	if(d==3) x1=x-1,y1=y;
	d1=d;
//	cout<<x1<<" "<<y1<<" "<<d1<<" "<<k<<" "<<ans<<endl;
	while(!pf(x1,y1)&&k>0){
		k--;
		d1=(d1+1)%4;
		x1=fx(d1,x);
		y1=fy(d1,y);
//		cout<<x1<<" "<<y1<<" "<<d1<<" "<<k<<" "<<ans<<endl;
	}
//	cout<<x1<<" "<<y1<<" "<<d1<<" "<<k<<" "<<ans<<endl;
	if(k<=0) return ans;
	k--;
	dfs(x1,y1,d1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	int i,j;
	while(T--){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		ans=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		cout<<dfs(x0,y0,d0)<<endl;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

1
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
