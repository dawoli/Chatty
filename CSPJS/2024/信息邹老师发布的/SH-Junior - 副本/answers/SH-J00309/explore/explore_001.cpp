#include<bits/stdc++.h>
using namespace std;
char a[1002][1002];
int T,n,m,k,x0,y0,d0,cnt;
int ans[5];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	cnt=T;
	while(T>0){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				cin>>a[i][j];
		a[x0][y0]='/';
		for(int i=0;i<k;){
			if(a[x0-1][y0]=='x'&&a[x0+1][y0]=='x'&&a[x0][y0-1]=='x'&&a[x0][y0+1]=='x')
				continue;
			if(d0==0&&i<k){
				if(y0+1<=m&&a[x0][y0+1]!='x'){
					y0=y0+1;
					a[x0][y0]='/';
				}
				else
					d0=d0+1;
				k=k-1;
			}
			if(d0==1&&i<k){
				if(x0+1<=m&&a[x0+1][y0]!='x'){
					x0=x0+1;
					a[x0][y0]='/';
				}
				else
					d0=d0+1;
				k=k-1;
			}
			if(d0==2&&i<k){
				if(y0-1>=1&&a[x0][y0-1]!='x'){
					y0=y0-1;
					a[x0][y0]='/';
				}
				else
					d0=d0+1;
				k=k-1;
			}
			if(d0==3&&i<k){
				if(x0-1>=1&&a[x0-1][y0]!='x'){
					x0=x0-1;
					a[x0][y0]='/';
				}
				else
					d0=d0-3;
				k=k-1;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]=='/')
					ans[cnt-T]++;
			}
		}
		T=T-1;
	}
	for(int i=0;i<cnt;++i){
		if(i<cnt-1)
			cout<<ans[i]<<endl;
		else
			cout<<ans[i];
	}
	return 0;
}
