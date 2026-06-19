#include<bits/stdc++.h>
using namespace std;
char a[2000][2000];
bool book[2000][2000];
int dir[2][4]={
0,1,0,-1,
1,0,-1,0
};
int n,m,k,x,y,d;
bool bj(int px,int py){
	return 1<=px&&px<=n&&1<=py&&py<=m;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>x>>y>>d;
		memset(book,0,sizeof book);
		memset(a,0,sizeof a);
		book[x][y]=1;
		int cnt=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%c",&a[i][j]);
			}
		}
		for(int i=1;i<=k;i++){
			int X=x+dir[0][d];
			int Y=y+dir[1][d];
			if(bj(X,Y)&&a[X][Y]!='x'){
				if(!book[X][Y]){
					book[X][Y]=1;
					cnt++;
				}
				x=X;
				y=Y;
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
