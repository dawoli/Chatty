#include <iostream>
#include <algorithm>
const int maxn = 1e5 + 5;

long long monster[maxn];
int flag[maxn];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	
	int n;
	std::cin >> n;
	
	long long strongest = -1, pos = 1;
	for(int i = 1; i <= n; ++i){
		long long attact;
		std::cin >> attact;
	
		if(monster[attact] == 0){
			flag[pos] = attact;	
			pos++;			
		}

		if(attact > strongest)
			strongest = attact;
		monster[attact]++;
	}
	
	std::sort(flag + 1, flag + pos);
	
	long long ans = 0;
	for(int i = 2; i <= pos; ++i){
		long long attact_able = monster[flag[i]];
		
		attact_able -= monster[flag[i - 1]];
		if(attact_able > 0){
			monster[flag[i - 1]] = 0;
			ans -= attact_able;
			if(ans < 0) ans = 0;
		}
		else{
			ans += -attact_able;
		}

	}
	
	std::cout << ans;
}
