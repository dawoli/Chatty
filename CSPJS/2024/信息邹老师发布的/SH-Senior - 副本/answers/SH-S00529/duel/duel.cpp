#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n,ans,ptr = 1,r[N];

int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	std::cin >> n;ans = n;
	for (int i = 1;i <= n;i++) std::cin >> r[i];
	std::sort(r + 1,r + 1 + n);
	for (int i = 1;i <= n;i++)
		if (r[i] != r[ptr])
			ptr++,ans--;
	std::cout << ans << '\n';
	
	return 0;
}
