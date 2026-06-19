#include <bits/stdc++.h>

const int N = 1e5 + 5;

int a[N],c[N],d[32][2 * N],X[4];
struct node{
	int num,ability;
}A[N],B[N];

int main(){
	
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T,K = 0,n,m;
	
	std::cin >> n >> m;
	for (int i = 1;i <= n;i++) std::cin >> a[i];
	for (int i = 1;i <= m;i++) std::cin >> c[i];
	for (int pw = 1;pw <= n;pw *= 2,K++);
	for (int R = 1;R <= K;R++)
		for (int expw = 1,G = 1;expw <= K - R;G *= 2,expw++)
			std::cin >> d[R][G];
	for (std::cin >> T;T--;){
		
		long long ans = 0;

		std::cin >> X[0] >> X[1] >> X[2] >> X[3];
		for (int i = 1;i <= n;i++) A[i].num = i,A[i].ability = a[i] ^ X[i % 4];
		for (int i = 1;i <= m;i++){
			
			int k = 0,cnt = c[i];
			
			for (int pw = 1;pw <= c[i];pw *= 2,k++);
			while (k--){
				
				int amount = cnt;
				
				cnt = 0;
				for (int j = 1,g = 1;j <= amount;j += 2,g++){
					
					if (d[i][g] == 0){
						
						if (A[j].ability >= i) B[++cnt] = A[j];
						else B[++cnt] = A[j + 1];
						
					}
					else{
						
						if (A[j + 1].ability >= i) B[++cnt] = A[j + 1];
						else B[++cnt] = A[j];
						
					}
					
				}
				for (int j = 1;j <= cnt;j++) A[j] = B[j];
				
			}
			ans ^= 1LL * i * A[1].num;
			
		}
		std::cout << ans << '\n';
		
	}
	
	return 0;
}
