#include <bits/stdc++.h>

const int N = 1e5 + 5;

bool use[N];
int n,m,L,V,ans,ans2,d[N],v[N],a[N],p[N];

void dfs(int x,int used){
	
	if (used >= ans2) return;
	if (x > m){
		
		int cnt = 0;
		
		for (int i = 1;i <= n;i++)
				for (int j = 1;j <= m;j++)
					if (use[j] && d[i] <= p[j] && 1LL * v[i] * v[i] + 2LL * a[i] * (p[j] - d[i]) > 1LL * V * V){
						cnt++;
						break;
					}
		if (cnt == ans) ans2 = std::min(ans2,used);
		
		return;
		
	}
	dfs(x + 1,used + 1);
	use[x] = false;
	dfs(x + 1,used);
	use[x] = true;
	
}

int main(){
	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	
	int T;
	
	for (std::cin >> T;T--;){
		
		bool A = 1,B = 1,C = 1;
		
		std::cin >> n >> m >> L >> V;
		ans = 0;ans2 = m;
		for (int i = 1;i <= n;i++){
			std::cin >> d[i] >> v[i] >> a[i];
			A = A && (a[i] == 0);
			B = B && (a[i] > 0);
			C = C && (a[i] < 0);
		}
		for (int i = 1;i <= m;i++) std::cin >> p[i];
		memset(use,true,sizeof(use));
		if (A){
			
			for (int i = 1;i <= n;i++)
				if (v[i] > V && d[i] <= p[m])
					ans++;
			std::cout << ans << ' ' << m - (bool)ans << '\n';
			
		}
		else if (B){
			
			for (int i = 1;i <= n;i++)
				if (d[i] <= p[m] && 1LL * v[i] * v[i] + 2LL * a[i] * (p[m] - d[i]) > 1LL * V * V)
					ans++;
			std::cout << ans << ' ' << m - (bool)ans << '\n';
			
		}
		else if (n <= 20 && m <= 20){
			
			for (int i = 1;i <= n;i++)
				for (int j = 1;j <= m;j++)
					if (d[i] <= p[j] && 1LL * v[i] * v[i] + 2LL * a[i] * (p[j] - d[i]) > 1LL * V * V){
						ans++;
						break;
					}
			std::cout << ans << ' ';
			dfs(1,0);
			std::cout << m - ans2 << '\n';
			
		}
		
	}
	
	return 0;
}
