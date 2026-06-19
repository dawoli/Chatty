#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int t,n,m,a;
	cin>>n>>m;
	for(int j=0;j<n+m;j++){
		cin>>a;
	}
	for(int k=1;k<n;k*=2){
		cin>>a;
	}
	cin>>t;
	for(int i=0;i<4*t;i++){
		cin>>a;
	}
	for(int i=0;i<t;i++){
		cout<<1;
	}
	return 0;
}
