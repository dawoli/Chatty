#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n,ans;
struct num{
	int val;
	bool color;//0:Red,1:Blue
}A[N];

int getscore(){
	
	int score = 0;
	
	for (int i = 1;i <= n;i++)
		for (int j = i - 1;j;j--)
			if (A[i].color == A[j].color){
				
				if (A[i].val == A[j].val) score += A[i].val;
				break;
				
			}
	
	return score;
}

void dfs(int x){
	
	if (x > n) {ans = std::max(ans,getscore());return;}
	dfs(x + 1);
	A[x].color = 1;
	dfs(x + 1);
	A[x].color = 0;
	
}

int main(){
	
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T;
	
	for (std::cin >> T;T--;){
		
		ans = 0;
		std::cin >> n;
		for (int i = 1;i <= n;i++) std::cin >> A[i].val,A[i].color = 0;
		dfs(1);
		std::cout << ans << '\n';
		
	}
	
	return 0;
}
