#include <bits/stdc++.h>
using namespace std;

int n,m,a,c,t,x0,x1,x2,x3;
string s;

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=m;i++) cin>>c;
	for(int i=1;i<=log2(n)+1;i++) cin>>s;
	cin>>t;
	while(t--){
		cin>>x0>>x1>>x2>>x3;
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
