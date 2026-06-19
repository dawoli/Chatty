#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1011;
int T,n,m,k;
bool u[1011][1011],vis[1011][1011];
int x0,y0,d0,cnt;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n>>m>>k;
		k++;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=1;j<=m;j++){
				if(s[j-1]=='x') u[i][j]=0;
				else u[i][j]=1;
				vis[i][j]=0;
			}
		}
		while(k){
			if(!vis[x0][y0]) cnt++;
			vis[x0][y0]=1;
			int nx=x0+dx[d0],ny=y0+dy[d0];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&u[nx][ny]) x0=nx,y0=ny;
			else d0=(d0+1)%4;
			k--;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//我永远喜欢珂朵莉
/*
2024-PJ-T2
姑且算他是模拟题吧
感觉一等奖分数线要>=250 
*/ 
