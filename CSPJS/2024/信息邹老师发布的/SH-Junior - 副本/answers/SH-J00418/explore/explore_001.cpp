#include<bits/stdc++.h>
using namespace std;
int n,m,k,sx,sy,dir,t,cnt;
char a[1001][1001];
int r[5]={0,1,0,-1};
int c[5]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cnt=0;
		cin>>n>>m>>k>>sx>>sy>>dir;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		a[sx][sy]='#';
		while(k){
			k--;
			int x=sx+r[dir],y=sy+c[dir];
			if(x>0&&y>0&&x<=n&&y<=m&&a[x][y]!='x'){
				sx=x;
				sy=y;
				a[sx][sy]='#';
			}else{
				dir=(dir+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='#') cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
	

