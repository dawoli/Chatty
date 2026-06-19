#include<bits/stdc++.h>
#define N 1001
using namespace std;
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	char M[N][N];
	bool v[N][N]={};
	int a;
	const int l[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	cin>>a;
	for(int i=0;i<a;i++) {
		int n,m,k,x,y,d,cnt;
		cin>>n>>m>>k>>x>>y>>d;
		cnt=1;
		for(int i=1;i<N;i++) {
			for(int j=1;j<N;j++) {
				v[i][j]=false;
			}
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>M[i][j];
			}
		}
		int X=x,Y=y,D=d;
		for(int j=0;j<k;j++) {
			v[X][Y]=true;
			int dx=X+l[D][0],dy=Y+l[D][1];
			if(dx>=1&&dy>=1&&dx<=n&&dy<=m&&M[dx][dy]=='.') {
				X=dx;
				Y=dy;
				if(!v[X][Y]) cnt++;
			}
			else D=(D+1)%4;
		}
		cout<<cnt<<'\n';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
