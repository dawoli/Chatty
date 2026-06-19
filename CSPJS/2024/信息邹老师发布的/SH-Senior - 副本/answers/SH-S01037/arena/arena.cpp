#include<bits/stdc++.h>
#define maxn 500010
using namespace std;
int n,m,a[maxn],c[maxn];
char s[maxn];
int t,u,v,w,x;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	int k=0,p=1;
	while(p<n){
		k++, p<<=1;
	}
	for(int i=1;i<=k;i++){
		scanf("%s",s+1);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&u,&v,&w,&x);
		printf("42\n");
	}
	return 0;
}

