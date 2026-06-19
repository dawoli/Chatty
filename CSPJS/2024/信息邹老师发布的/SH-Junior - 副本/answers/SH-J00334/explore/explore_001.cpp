#include<bits/stdc++.h>
using namespace std;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		vector< vector< bool > > ma(1005,vector<bool>(1005,false)),flag(1005,vector<bool>(1005,false));	
		int n,m,k,x,y,d,cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
			cin>>a;
			if(a==46) ma[i][j]=true;
			if(a==120) ma[i][j]=false;
		}
		flag[x][y]=true;
		for(int i=0;i<k;i++){
			if(x+dx[d]>=1&&x+dx[d]<=n&&y+dy[d]>=1&&y+dy[d]<=m&&ma[x+dx[d]][y+dy[d]]){
				x=x+dx[d];
				y=y+dy[d];
				if(flag[x][y]) continue;
				else{
					flag[x][y]=true;
					cnt++;
				}
			}else{
				d=(d+1)%4;
			}
		}
		cout<<cnt+1<<"\n";
	}
}
