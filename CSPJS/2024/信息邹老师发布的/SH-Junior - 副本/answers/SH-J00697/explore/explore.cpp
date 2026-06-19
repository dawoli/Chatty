#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e3+2;

int n, m, k, T, vis[N][N];
string s[N];
char cc[N];
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin.tie(0);
	cin>>T;
	while(T--){
		memset(vis, 0, sizeof vis);
		int sx=0, sy=0, d;
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		vis[sx][sy]=1;
		for(int i=1;i<=n;i++){
			scanf("%s", cc);
			string tt=cc;
			s[i]=" "+tt;
		}
		while(k--){
			int nx=sx, ny=sy;
			if(d==0)ny++;
			if(d==1)nx++;
			if(d==2)ny--;
			if(d==3)nx--;
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&s[nx][ny]=='.'){
				sx=nx;sy=ny;
				vis[sx][sy]=1;
			}
			else d=(d+1)%4;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j])cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
