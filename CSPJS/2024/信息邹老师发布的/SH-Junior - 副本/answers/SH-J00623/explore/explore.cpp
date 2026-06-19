#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const int N = 1e3+7;
char a[N][N],b[N][N];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m,k,x,y,d,cnt=0,sum=1;
void dfs(int xx,int yy,int dd) {
	if(cnt==k) {
		return ;
	}
	for(int i=dx[dd],j = dy[dd],s=1; cnt<k,s<=4; cnt++,s++,dd=(dd+1)%4,i=dx[dd],j=dy[dd]) {
		int ux = xx+i,uy = yy+j;
		if(ux<1 || ux>n || uy<1 || uy>m || a[ux][uy]=='X') {
			continue;
		}
		if(cnt<k) {
			cnt++;
			if(b[ux][uy]==0) {
				b[ux][uy] = 1;
				sum++;
			}
//			cout<<ux<<" "<<uy;
			dfs(ux,uy,dd);
		}
	}	
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>m>>k>>x>>y>>d; 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cnt=0,sum=1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>a[i][j];
			}
		}
		b[x][y] = 1;
		dfs(x,y,d);
		cout<<sum<<"\n";
	}
	return 0;
} 
