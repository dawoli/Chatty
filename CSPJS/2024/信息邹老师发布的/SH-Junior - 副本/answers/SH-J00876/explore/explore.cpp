#include<bits/stdc++.h>
using namespace std;
int n,cnt,T,m,d,k,sx,sy,c[1005][1005];
char dt[1005][1005];
void dfs(int fx,int i,int x,int y){
	if(c[x][y]==0){
		cnt++;
		c[x][y]=1;
	}
	if(i==0){
		return;
	}
	int tox=x,toy=y;
	if(fx%2==0){
		toy-=fx-1;
	}
	else{
		tox-=fx-2;
	}
	if(dt[tox][toy]=='x'||tox>n||tox<=0||toy>m||toy<=0) dfs((fx+1)%4,i-1,x,y);
	else{
		dfs(fx,i-1,tox,toy);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int ij=1;ij<=T;ij++){
		cnt=0;
		cin>>n>>m>>k>>sx>>sy>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>dt[i][j];
			}
		}
		dfs(d,k,sx,sy);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				c[i][j]=0;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//2
//1 5 4
//1 1 2
//....x
//5 5 20
//1 1 0
//.....
//.xxx.
//.x.x.
//..xx.
//x....
