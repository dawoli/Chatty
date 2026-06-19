#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t,n,m,k,x0,y0,d;
	int sum[1005];
	cin>>t;
	for(int i=1;i<=t;++i){
		char c[1005][1005];
		int a[1005][1005];
		int b[1005][1005]={0};
		cin>>n>>m>>k; 
		cin>>x0>>y0>>d;
		for(int p=1;p<=n;++p){
			for(int j=1;j<=m;++j){
				cin>>c[p][j];
			} 
		}
		int x1=x0,y1=y0;
		int y=a[x1][y1];
		b[x1][y1]=1;
		for(int p=1;p<=k;++p){
			if(d==3){
				if(c[x1-1][y1]!='x' && x1-1>=1){
					x1--;
					b[x1][y1]=1;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else if(d==2){
				if(c[x1][y1-1]!='x' && y1-1>=1){
					y1--;
					b[x1][y1]=1;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else if(d==1){
				if(c[x1+1][y1]!='x' && x1+1<=n){
					x1++;
					b[x1][y1]=1;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
			else if(d==0){
				if(c[x1][y1+1]!='x' && y1+1<=m){
					y1++;
					b[x1][y1]=1;
				}
				else{
					d=(d+1)%4;
					continue;
				}
			}
		}
		long long ans=0;
		for(int p=1;p<=1000;++p){
			for(int j=1;j<=1000;++j){
				if(b[p][j]==1){
					ans++;
				}
			} 
		}
		sum[i]=ans;
	}
	for(int i=1;i<=t;++i){
		cout<<sum[i]<<endl;
	}
	return 0;
} 
