#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,m,k,x,y,d,a[1010][1010],b[1010][1010];
		cin>>n>>m>>k>>x>>y>>d;
		for(long long p=1;p<=n;p++)
			for(long long j=1;j<=m;j++){
				a[p][j]=0;
				char s;
				cin>>s;
				if(s=='.')
					b[p][j]=1;
				if(s=='x')
					b[p][j]=0;
			}
		a[x][y]=1;
		for(long long p=1;p<=k;p++){
			if(d==0){
				if(y+1>m){
					d=1;
					continue;
				}
				else if(b[x][y+1]==1){
					a[x][y+1]=1;
					y=y+1;
				}
				else{
					d=1;
					continue;
				}
			}
			if(d==1){
				if(x+1>n){
					d=2;
					continue;
				}
				else if(b[x+1][y]==1){
					a[x+1][y]=1;
					x=x+1;
				}
				else{
					d=2;
					continue;
				}
			}
			if(d==2){
				if(y-1==0||y-1<0){
					d=3;
					continue;
				}
				else if(b[x][y-1]==1){
					a[x][y-1]=1;
					y=y-1;
				}
				else{
					d=3;
					continue;
				}
			}
			else{
				if(x-1==0||x-1<0){
					d=0;
					continue;
				}
				else if(b[x-1][y]==1){
					a[x-1][y]=1;
					x=x-1;
				}
				else{
					d=0;
					continue;
				}
			}
		}
		long long ans=0;
		for(long long p=1;p<=n;p++)
			for(long long j=1;j<=m;j++){
				if(a[p][j]==1)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
