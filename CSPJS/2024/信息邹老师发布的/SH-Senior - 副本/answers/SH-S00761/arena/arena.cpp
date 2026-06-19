#include<bits/stdc++.h>
using namespace std;
int t,n,a[2009],f[2009][2][2009]
int d(int x,int y){
	if(x==y) return x;
	else return 0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=2;i<=n;++i){
			for(int j=0;j<i-1;++j){
				if(j==0) f[i][0][0]=d(a[i],a[i-1])+f[i-1][0][0];
				else if(j==i-2){
					int t1=f[i-1][1][0];
					for(int k=1;k<i-2;++k) t1=max(t1,f[i-1][1][k]);
				}
			}
		}
	}
	return 0;
}

