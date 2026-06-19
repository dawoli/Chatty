#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
	int a,id;
}s[105];
int n,m;

bool cmp(Node x,Node y){
	return x.a>y.a;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&s[i].a);
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].id==1){
			int x=(int)ceil(1.0*i/n);
			printf("%lld ",x);
			if(x&1) printf("%lld",i-(x-1)*n);
			else printf("%lld",x*n-i+1);
			return 0;
		}
	}
	return 0;
}
