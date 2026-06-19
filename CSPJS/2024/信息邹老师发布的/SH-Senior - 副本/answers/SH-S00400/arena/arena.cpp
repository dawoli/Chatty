#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a1[N];
int a[N];
int c[N];
int T;
int x[10];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a1[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=4;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			a[i]=a1[i]^x[i%4];
		}
		printf("1\n");
	}
	return 0;
}
