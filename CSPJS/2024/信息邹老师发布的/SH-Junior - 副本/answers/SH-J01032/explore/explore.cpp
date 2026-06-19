#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int t;
char c[N][N];
bool book[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	for (int i=1;i<=t;i++){
		int n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				cin>>c[j][k];
		book[x][y]=true;
		for (int j=1;j<=k;j++){
			if (d==0&&c[x][y+1]=='.'&&y<m) y++,book[x][y]=true;
			else if (d==1&&c[x+1][y]=='.'&&x<n) x++,book[x][y]=true;
			else if (d==2&&c[x][y-1]=='.'&&y>1) y--,book[x][y]=true;
			else if (d==3&&c[x-1][y]=='.'&&x>1) x--,book[x][y]=true;
			else d=(d+1)%4;
		}
		for (int j=1;j<=n;j++)
			for (int k=1;k<=m;k++)
				if (book[j][k]) cnt++,book[j][k]=false;
		cout<<cnt<<endl;
	}
	return 0;
}
