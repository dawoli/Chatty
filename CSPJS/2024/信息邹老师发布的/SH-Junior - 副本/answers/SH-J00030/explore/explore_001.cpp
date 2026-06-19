#include<bits/stdc++.h>
using namespace std;
char a[10009][10009];
void input(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
}
void c(int d,int x1,int y1,int x,int y){
	if(d==0) y1=y+1;
	else if(d==1) x1=x+1;
	else if(d==2) y1=y-1;
	else y1=x-1;
}
void calc(int n,int m,int k,int x,int y,int d){
	int x1,y1,ans=0;
	for(int i=1;i<=k;i++){
		if(a[x][y]=='.'){
			a[x][y]='b';
		}
		c(d,x1,y1,x,y);
		if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]!='x'){
			if(d==0) y=y+1;
			else if(d==1) x=x+1;
			else if(d==2) y=y-1;
			else x=x-1;
		}
		else{
			d=(d+1)%4;
			continue;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='b') ans++;
		}
	} 
	cout<<ans<<endl;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,m,k,x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		input(n,m);
		calc(n,m,k,x,y,d);
	}
	return 0;
}
