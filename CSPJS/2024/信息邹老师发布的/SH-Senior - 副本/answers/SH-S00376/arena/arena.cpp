#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int K;
	if(pow(2,log(n))<n) K=log(n)+1;
	else K=log(n);
	for(int i=K;i>=1;i--){
		cin>>s[K];
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=3;j++){
			cin>>x[i];
		}
		for(int j=1;j<=n;j++){
			b[j]=a[j]^(x[j%4]);
		}
		for(int j=1;j<=m;j++){
		}
	}
	return 0;
}
/*
0 2 2 1 2
  3 3 3 2
  4 4   3

*/
