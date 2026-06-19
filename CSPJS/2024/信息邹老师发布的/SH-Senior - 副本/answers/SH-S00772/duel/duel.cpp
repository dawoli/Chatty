#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, r[N];
bool vst[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	int l = 1, j = 1;
	for(l = 1; l <= n; l++){
		while(r[j] <= r[l] && j <= n) j++;
		if(j == n + 1)
			break;
		vst[l] = 1;
		j++;
	}
	int ans = n;
	for(int i = 1; i <= n; i++)
		ans -= vst[i];
	printf("%d\n", ans);
	return 0;
}


