#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
char a[1010][1010];
int v[1010][1010];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;++j)
			for(int l=1;l<=m;++l)
				cin>>a[j][l];
		v[x][y]=1;
		for(int j=1;j<=k;++j){
			if(d==0){
				if(y+1<=m&&a[x][y+1]=='.')
					++y;
				else
					d=1;
			}else if(d==1){
				if(x+1<=m&&a[x+1][y]=='.')
					++x;
				else
					d=2;
			}else if(d==2){
				if(y-1>=1&&a[x][y-1]=='.')
					--y;
				else
					d=3;
			}else if(d==3)
				if(x-1>=1&&a[x-1][y]=='.')
					--x;
				else
					d=0;
			v[x][y]=1;
		}
		long long cnt=0;
		for(int j=1;j<=n;++j)
			for(int l=1;l<=m;++l)
				if(v[j][l])
					++cnt;
		cout<<cnt<<endl;
	}
	return 0;
}
