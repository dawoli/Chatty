#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[2147483647],x[5],aa[2147483647],k,tw,tww,c[2147483647],th[2147483647];
string roo[100];
char ro;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	k=1;tw=2;
	while(tw<n){
		tw*=2;
		k++;
	}
	for(int i=n+1;i<=tw;i++){
		a[i]=k;
	}
	for(int i=1;i<=k;i++){
		cin>>roo[i];
	}
	for(int T=1;T<=t;T++){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++){
			aa[i]=a[i]^x[i%4];
		}
		
		for(int i=1;i<=tw;i++){
			th[i]=i;
		}
		tww=tw;
		for(int i=1;i<=k;i++){
			tww/=2;
			for(int j=1;i<=tww;t++){
				ro=roo[i][j-1];
			}
		}
		cout<<0;
	}
	return 0;
}
