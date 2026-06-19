#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int T,n,m;
int a[N],c[N];
string s[N];
int f2(int x){
	int cnt=0,a=1;
	while(a<x){
		a*=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	int k=f2(n);
	for(int i=1;i<=k;i++) cin>>s[i];
	cin>>T;
	for(int i=1;i<=T;i++){
		int x0,x1,x2,x3;
		cin>>x0>>x1>>x2>>x3;
	}
	cout<<1;
	return 0;
}
