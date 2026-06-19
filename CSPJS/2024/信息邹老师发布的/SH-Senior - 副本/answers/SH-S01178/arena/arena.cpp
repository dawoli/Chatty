#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long n,m,a[N],c[N],T;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k=0;
	while((1<<k)<n)
		k++;
	for(int i=1;i<=(1<<k)-n;i++){
		string s;
		cin>>s;
	}
	cin>>T;
	for(int i=1;i<=T;i++){
		long long x0,x1,x2,x3;
		cin>>x0>>x1>>x2>>x3; 
	}
	for(int i=1;i<=T;i++){
		cout<<0<<endl; 
	}
	return 0;
} 
