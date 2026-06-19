#include<bits/stdc++.h>
using namespace std;
int n,m,k,ct=1;
int x,y,d;
int jd[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char xy[1005][1005];
int walk(){
	int tx=x+jd[d][0],ty=y+jd[d][1];
	if(tx<=0||tx>n||ty<=0||ty>m||xy[tx][ty]=='x'){
		d=(d+1)&3;
		return 0;
	}
	x=tx,y=ty;
	if(xy[x][y]=='.'){
		xy[x][y]=',';
		return 1;
	}
	return 0;
}
int main(){
	cin.tie(nullptr);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	string s;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<=m;j++){
				xy[i][j+1]=s[j];
			}
		}
		ct=1;
		xy[x][y]=',';
		while(k){
			k--;
			ct+=walk();
		}
		cout<<ct<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
