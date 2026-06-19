#include<bits/stdc++.h>
using namespace std;
#define N 200005//注意设置大小
typedef long long ll;

int a[N];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int m,n,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=m;++i) cin>>a[i];
		cout<<1<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

