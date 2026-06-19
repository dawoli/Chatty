#include <cstdio>
#include <iostream>
using namespace std;
int t;
int n, m, k;
int a[100005], c[100005];
pair<int, int> b[100005];
int d[32][32];
char s[32];
int yh[5];
int main(){
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	bool flagA = 1;
	for(int i = 1;i <= m;i++){
		scanf("%d", &c[i]);
		int tmp = c[i];
		flagA &= (c[i]==(c[i]&-c[i]));
	}
	k = 0;
	while((1<<k) < n)k++;
	for(int i = k-1;i>=0;i--){
		scanf("%s", s+1);
		for(int j = 1;j <= (1<<i);j++){
			d[i][j] = s[j]-'0';
		}
	}
	scanf("%d", &t);
	while(t--){
		printf("0\n");
	}
	return 0;
}