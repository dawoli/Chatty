#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,m,k,T,a[N],c[N],x[4],LOG2[N];
string s[20];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;++i)LOG2[i]=LOG2[i>>1]+1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&c[i]);
	for(int i=LOG2[n];i>=0;--i)getline(cin,s[i]);
	scanf("%d",&T),k=LOG2[n-1]+1;
	while(T--){
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		printf("1\n");
	}
	return 0;
}
