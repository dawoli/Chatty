#include<bits/stdc++.h>
using namespace std;
#define N 520
#define mod 998244353

int n,m;
bool s[N];
int c[N],u[N];

int bf(int pos,int lv){ //I've tried my best,i can't get 1=
	if(pos == n + 1)return (m <= n - lv);
	int res = 0;
	for(int x = 1;x <= n;++x){
		if(u[x])continue;
		u[x] = 1;
		res += bf(pos + 1,lv + (c[x] <= lv || !s[pos]));
		u[x] = 0;
	}
	return res;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i){
		char c;cin>>c;
		s[i] = (c == '1');
	}
	for(int i = 1;i <= n;++i)scanf("%d",&c[i]);
	printf("%d",bf(1,0));
	return 0;
}
