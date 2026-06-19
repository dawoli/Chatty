#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n, r, mi = 0x7fffffff, t[100001], ans, mx;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &r); 
		t[r]++;
		mx = max(mx, r);
	}
	sort(t+1, t+mx+1, cmp);
	printf("%d", t[1]);
	return 0;
}
