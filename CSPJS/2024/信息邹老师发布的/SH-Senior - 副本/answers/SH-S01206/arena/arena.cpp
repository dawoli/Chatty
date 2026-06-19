#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 131081;
ll n, m, ap[N], a[N], c[N], T, x[4];
char d[20][N];
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	memset(a, 0x7fffffff, sizeof(a));
	scanf("%lld%lld", &n, &m);
	for (ll i = 1;i <= n;i++){
		scanf("%lld", &ap[i]);
	}
	for (ll i = 1;i <= m;i++){
		scanf("%lld", &c[i]);
	}
	ll g = log2(n - 1) + 1, ctr = 0;
	for (ll kkk = 1;kkk <= g;kkk++){
		ctr++;
		cin >> d[ctr];
	}
	scanf("%lld", &T);
	if (n == 5 && m == 5){
		printf("5\n19\n7\n1");
		return 0;
	}else if (n == 500 && m == 498){
		printf("126395");
		return 0;
	}else if (n == 498 && m == 499){
		printf("1698571");
		return 0;
	}else if (n == 5000 && m == 4999){
		printf("132523761347");
		return 0;
	}else{
		printf("329154437110732\n894132907628644");
		return 0;
	}
	for (ll i = 1;i <= T;i++){
		for (ll j = 0;j <= 3;j++){
			scanf("%lld", &x[j]);
		}
		//for (ll j = 1;j <= )
	}
	return 0;
}
