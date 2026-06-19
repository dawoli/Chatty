#include <iostream>
#include <algorithm>
#include <cstdlib>
int n;
int cnt[100010];
int cnt_use[100010];
int max_attack, res;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		int t;
		scanf("%d",&t);
		max_attack = max_attack < t ? t : max_attack;
		cnt[t]++;
	}
	for(int i = 1;i <= max_attack;++i){
		cnt_use[i] = cnt[i];
	}
	for(int i = 1;i < max_attack;++i){
		int j = i + 1;
		while(cnt[i] > 0 && j <= max_attack){
			int use = std::min(cnt[i],cnt_use[j]);
			cnt[i] -= use;
			cnt_use[j] -= use;
			j++;
		}
	}
	for(int i = 1;i <= max_attack;++i){
		res += cnt[i];
	}
	printf("%d", res);
	return 0;
}
