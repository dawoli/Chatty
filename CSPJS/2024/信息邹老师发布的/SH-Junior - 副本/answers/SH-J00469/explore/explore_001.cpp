#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[1010][1010];
int vis[1010][1010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		long long k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		long long ans=0;
		for(int i=0;i<1010;i++){
			for(int j=0;j<1010;j++){
				vis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			s=' '+s;
			for(int j=1;j<=m;j++){
				a[i][j]=s[j];
			}
		}
		vis[x][y]=1;
//		cout<<x<<" "<<y<<" "<<a[x][y]<<endl;
		vis[x][y]=1;
		for(long long i=0;i<k;i++){
			int nx=x,ny=y;
			if(d==0){
				ny++;
			} 
			else if(d==1){
				nx++;
			}
			else if(d==2){
				ny--;
			}
			else{
				nx--;
			}
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.'){
//				cout<<nx<<" "<<ny<<" "<<a[nx][ny]<<endl;
				vis[nx][ny]=1;
				x=nx;
				y=ny;
			}
			else{
				d=(d+1)%4;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ans+=(long long)vis[i][j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
