#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int n, maxr;
int cnt[MAXN];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	int t;
	maxr = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &t);
		cnt[t]++;
		maxr = max(t, maxr);
	}
	int lft = 0;
	for(int i = 1;i <= maxr;i++){
		if(!cnt[i])continue;
		lft = (lft >= cnt[i] ? lft - cnt[i] : 0); 
		lft += cnt[i];
	}
	printf("%d", lft);
	return 0;
}

