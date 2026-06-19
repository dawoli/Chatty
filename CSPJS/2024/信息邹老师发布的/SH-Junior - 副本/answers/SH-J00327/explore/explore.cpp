#include<bits/stdc++.h>
using namespace std;
const int N=1009,xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int n,m,k;
bool f[N][N];
bool v[N][N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				char a;
				cin>>a;
				if(a=='.')
					f[i][j]=true;
				else
					f[i][j]=false;
			}
		for(int i=1;i<=n;i++)
			f[i][0]=f[i][m+1]=false;
		for(int j=1;j<=m;j++)
			f[0][j]=f[n+1][j]=false;
		v[x][y]=true;
		int ans=1;
		for(int i=1;i<=k;i++){
			int x_=x+xx[d],y_=y+yy[d];
			if(f[x_][y_]){
				x=x_,y=y_;
				if(!v[x][y])
					v[x][y]=true,ans++;
			}
			else{
				d=(d+1)%4;
			}
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
}
