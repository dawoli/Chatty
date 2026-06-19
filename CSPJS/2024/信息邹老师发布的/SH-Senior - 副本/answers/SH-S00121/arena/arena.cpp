#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[100100];
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int lns=1;
	while(pow(2,lns)<n) lns++;
	string c[30];
	for(int i=1;i<=lns;i++){
		cin>>c[i];
	}
	int T;
	cin>>T;
	while(T--){
		int x0,x1,x2,x3;
		cin>>x0>>x1>>x2>>x3;
	}
	return 0;
}
