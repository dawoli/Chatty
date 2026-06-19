#include<iostream>
#include<cstdio>
const int N = 1e5+7;
typedef long long ll;
void quick(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}
int a[N],c[N];
int n,m,k;
char d[20][N];
int X[5];
void solve(){
	for(int i=0;i<4;++i)std::cin>>X[i];
}
int main(){
	std::freopen("arena.in","r",stdin);
	std::freopen("arena.out","w",stdout);
	quick();
	int T;
	std::cin>>T;
	std::cin>>n>>m;
	for(int i=1;i<=n;++i)std::cin>>a[i];
	for(int i=1;i<=m;++i)std::cin>>c[i];
	k=1;
	while(1<<(k-1)<=n)++k;
	for(int i=1;i<=k;++i)for(int j=1;j<=1<<(r-i);++j)std::cin>>d[i][j];
	while(T--)solve();
	return 0;
}
