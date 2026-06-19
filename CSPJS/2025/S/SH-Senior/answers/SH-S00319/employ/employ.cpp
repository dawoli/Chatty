#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const long long MOD = 998244353;
int n, m;
int a[MAXN];
int c[MAXN];
bool b[MAXN];
long long ans;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	char ctmp = getchar();
	while(ctmp != '0' && ctmp != '1')ctmp = getchar();
	for(int i = 1;i <= n;i++){
		b[i] = (ctmp == '1');
		ctmp = getchar();
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &c[i]);
	}
	for(int i = 1;i <= n;i++){
		a[i] = i;
	}
	do{
		int cntrej = 0, cntpas = 0;
		for(int i = 1;i <= n;i++){
			if(!b[i])cntrej++;
			else{
				if(cntrej >= c[a[i]])cntrej++;
				else cntpas++;
			}
		}
		if(cntpas >= m)ans++;
	}while(next_permutation(a + 1, a + n + 1));
	printf("%lld", ans);
	return 0;
}
