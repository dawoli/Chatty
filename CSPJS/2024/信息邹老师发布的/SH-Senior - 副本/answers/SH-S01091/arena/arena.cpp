#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,a1[N],c[N],T,x[4],a[N],ans[N][30];
string d[30];
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
	for(int i=1;i<=log2(n-1)+1;i++){
		cin>>d[i];
	}
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<=n;i++){
			a[i]=a1[i]^x[i%4];
		}
		for(int i=1;i<=m;i++){
			
		}
	}
	return 0;
}
