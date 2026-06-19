#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
long long v[1005][1005];
long long t,n,m,k;
long long dx[]={0,1,0,-1};
long long dy[]={1,0,-1,0};
void dfs(long long x,long long y,long long dir,long long bs,long long sum){
//	cout<<"dfs("<<x<<","<<y<<","<<dir<<","<<bs<<","<<sum<<");"<<endl; 
	if(bs==0){
		cout<<sum<<endl;
		return ;
	}
	long long tx=x+dx[dir];
	long long ty=y+dy[dir];
//	cout<<tx<<" "<<ty<<" "<<n<<" "<<m<<endl;
	if(tx<1||ty<1||tx>n||ty>m||a[tx][ty]=='x'){
//		cout<<1<<endl;
		dfs(x,y,(dir+1)%4,bs-1,sum);
	}else{
//		cout<<2<<endl;
		if(v[tx][ty]==1){
			dfs(tx,ty,dir,bs-1,sum);
		}else{
			v[tx][ty]=1;
			dfs(tx,ty,dir,bs-1,sum+1);
		}
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		long long x,y,d;
		cin>>n>>m>>k>>x>>y>>d;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		v[x][y]=1;
		dfs(x,y,d,k,1);
	}
}
