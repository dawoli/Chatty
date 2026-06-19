#include<bits\stdc++.h>
using namespace std;
int T;
char l[1111][1111];
short nx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,k,x,y,d;
int f(int x,int y,int stp,int d,int k){
	if(k==0){
		return stp;
	}
	int tx=x+nx[d][0];
	int ty=y+nx[d][1];
	if(tx>n or ty>m or l[tx][ty]=='x')return f(x,y,stp,(d+1)%4,k-1);
	return f(tx,ty,stp+1,d,k-1);
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>l[i][j];
		cout<<f(x,y,1,d,k)<<endl;
	}
	return 0;
} 
