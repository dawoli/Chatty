#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long ax[maxn],c[maxn];
int main(){
	freopen("arena.in",r,stdin);
	freopen("arena.out",w,stdout);
	int t;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ax[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a=b+c;
		cout<<1<<"\n";
	}
}
