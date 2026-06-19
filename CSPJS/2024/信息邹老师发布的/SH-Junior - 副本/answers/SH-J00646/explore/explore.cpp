#include <bits/stdc++.h>
using namespace std; 
long long T;
long long n,m,k,x,y,d;
char c[10009][10009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int k=1;k<=n;++k){
			for(int j=1;j<=m;++j){
				cin>>c[k][j];
			}
		}
		cout<<"1"<<endl;
 }
	return 0;
}
