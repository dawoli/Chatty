#include<iostream>

using namespace std;

long long T,m,n,k,x,y,d,ans;
long long a[10009][10009];
long long b[10009][10009];
string s;

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>m>>n>>k;
		cin>>x>>y>>d;
		for(long long i=1;i<=m+2;i++){
			a[i][1]=1000000;
			a[i][n+2]=1000000;
		}
		for(long long i=1;i<=n+2;i++){
			a[1][i]=1000000;
			a[m+2][i]=1000000;
		}
		cin>>s;
		for(int i=2;i<=m+1;i++){
			for(long long j=2;j<=n+1;j++){
				long long xy=(i-2)*m+j-1;
				if(s[xy-1]=='.') a[i][j]=0;
				else a[i][j]=1000000;
			}
		}
//		for(int i=1;i<=m+2;i++){
//			for(int j=1;j<=n+2;j++){
//				if(a[i][j]==0)	cout<<a[i][j]<<"     ";
//				else cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		x=x+1;
		y=y+1;
		ans=1;
		for(long long i=1;i<=k;i++){
			if(d==0 and a[x][y+1]==0){
				if(b[x][y+1]==0){
					ans++;
					b[x][y+1]=1;
//					cout<<x-1<<","<<y+1-1<<endl;
					y=y+1;
				}
			}
			else if(d==1 and a[x+1][y]==0){
				if(b[x+1][y]==0){
					ans++;
					b[x+1][y]=1;
//					cout<<x+1-1<<","<<y-1<<endl;
					x=x+1;
				}
			}
			else if(d==2 and a[x][y-1]==0){
				if(b[x][y-1]==0){
					ans++;
					b[x][y-1]=1;
//					cout<<x-1<<","<<y-1-1<<endl;
					y=y-1;
				}
			}
			else if(d==3 and a[x-1][y]==0){
				if(b[x-1][y]==0){
					ans++;
					b[x-1][y]=1;
//					cout<<x-1<<","<<y-1<<endl;
					x=x-1;
				}
			}
			else d=(d+1)%4;
		}
		cout<<ans<<endl;
	}
	return 0;
}
