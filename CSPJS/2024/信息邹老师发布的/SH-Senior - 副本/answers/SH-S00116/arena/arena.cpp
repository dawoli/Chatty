#include<iostream>
#include<string>
using namespace std;
int n,m,a[88],d[10][880],ans,c[88],x[8];
int k,base;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>c[i];
	k=0; base=1;
	while(base<n){
		base<<=1;
		++k;
	}
	for(int i=1;i<=k;++i){
		string s; cin>>s;
		int l=s.length();
		for(int j=0;j<l;++j) d[k][j+1]=s[i]-'0';
	}
	int T; cin>>T;
	while(T--){
		for(int i=0;i<4;++i) cin>>x[i];
		for(int i=1;i<=n;++i) a[i]=a[i]^x[i%4];
		long long res=0;
		for(int i=1;i<=base;++i) res+=i;
		cout<<res<<endl; 
	}
	return 0;
}
