#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int d,x,y;
bool v[1005][1005]={0},vis[1005][1005]={0};
int dx[8]={0,1,0,-1};
int dy[8]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);//fsdfhbnsfdsddrguhdcbcdhddddd
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		long long cnt=1;//起点+1 
		v[x][y]=1;//起点为1 
		for(int i=0;i<=m+1;i++) v[n+1][i]=1;//底 
		for(int i=0;i<=m+1;i++) v[0][i]=1;//tou 
		for(int i=0;i<=n+1;i++) v[i][0]=1;//zuo
		for(int i=0;i<=n+1;i++) v[i][m+1]=1;//you
		
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){//每一个 用J 
				if(s[j]=='x') v[i][j+1]=1;//标记障碍 
			}
		}
//		cout<<endl;
//		for(int i=0;i<=n+1;i++){//test
//			for(int j=0;j<=m+1;j++) if(v[i][j]==1){cout<<'x';}else cout<<".";
//			cout<<endl;
//		}cout<<endl<<endl;
		for(int i=1;i<=k;i++){
			int ex=x+dx[d];
			int ey=y+dy[d];
			if(v[ex][ey]==1||vis[ex][ey]==1){
				d=(d+1)%4;
				continue;
			}if(vis[ex][ey]==0){
				cnt++;
				vis[ex][ey]=1;
			}
			//cout<<cnt<<":  "<<ex<<" "<<ey<<endl; 
			x=ex;
			y=ey;
		}cout<<cnt<<endl;
//		cout<<endl;
//		for(int i=0;i<=n+1;i++){//test
//			for(int j=0;j<=m+1;j++) if(v[i][j]==1){cout<<'x';}else cout<<".";
//			cout<<endl;
//		}cout<<endl<<endl;
	}
}
/*2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....*/
//cout<<endl;
//		for(int i=0;i<=n+1;i++){//test
//			for(int j=0;j<=m+1;j++) if(v[i][j]==1){cout<<'x';}else cout<<".";
//			cout<<endl;
//		}cout<<endl<<endl;
