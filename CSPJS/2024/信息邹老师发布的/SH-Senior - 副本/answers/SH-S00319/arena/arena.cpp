#include<bits/stdc++.h>
using namespace std;
int n,m,t,c,a;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c;
	while(m--) cin>>a;
	while(t--){
		cout<<rand()%n+1<<"\n";
	}
	return 0;
}
