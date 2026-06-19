#include <bits/stdc++.h>
using namespace std;
int t,n,m,d,x,y,k;  //数据组数、行数、列数、朝向、机器人所在行、列、操作次数
char a[1005][1005];
/*
模拟 
*/
void func(){
	int ans=0;
	cin>>n>>m>>k;
	cin>>x>>y>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	ans++;
	a[x][y]='/';
	for(int i=0;i<k;i++){
		int nx,ny;
		if(d==0){
			nx=x;
			ny=y+1;
		}
		else if(d==1){
			nx=x+1;
			ny=y;
		}
		else if(d==2){
			nx=x;
			ny=y-1;
		}
		else if(d==3){
			nx=x-1;
			ny=y;
		}
		if(1<=nx&&nx<=n && 1<=ny&&ny<=m && a[nx][ny]!='x'){
			x=nx;
			y=ny;
			if(a[nx][ny]=='.'){
				ans++;
				a[nx][ny]='/';  //标记为已走过
			} 
		}
		else d=(d+1)%4;
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		func();
	}
	return 0;
}
