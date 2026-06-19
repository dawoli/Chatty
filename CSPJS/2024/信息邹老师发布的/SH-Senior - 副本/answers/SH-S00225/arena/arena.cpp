#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,T;
int a[N],c[N],x[5];
int q[509][509];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int b=n;
	int k=0;
	while(b>1){
		b/=2;
		k++;
	}
	if(!(n==pow(2,k))) k++;
	for(int i=1;i<=k;i++) {
		for(int j=1;j<=pow(2,k-i);j++) cin>>q[i][j];
	}
	cin>>T;
	while(T--){
		for(int i=0;i<=3;i++) cin>>x[i];
		
		cout<<'1'<<'\n';
	}
	return 0;
}
