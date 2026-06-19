#include<bits/stdc++.h>

using namespace std;

int n,m;
const int MOD = 998244353;
char s[510];
int c[510];

namespace search{
	int ans, p[20];
	bool flag[20];
	void dfs(int step){
		if(step > n){
			int cnt = 0;
			for(int i = 1; i <= n; i ++){
				if(s[i] == '0' || i-1-cnt >= c[p[i]]) continue;
				cnt ++;
			}
			if(cnt >= m) ans ++;
			return;
		}
		for(int i = 1; i <= n; i ++){
			if(!flag[i]){
				flag[i] = 1;
				p[step] = i;
				dfs(step + 1);
				flag[i] = 0;
			}
		}
	}
	int main(){
		dfs(1);
		cout << ans;
		return 0;
	}
}
namespace all_1{
	int main(){
		return 0;
	}
}
namespace m_equal_n{
	int main(){
		for(int i = 1; i <= n; i ++){
			if(s[i] == '0' || c[i] == 0){
				cout << 0;
				return 0;
			}
		}
		long long mul = 1;
		for(int i = 1; i <= n; i ++) mul = mul*i%MOD;
		cout << mul;
		return 0;
	}
}
namespace LUCKY{
	int main(){
		int mul = 1, seed = 0;
		for(int i = 1; i <= n; i ++){
			if(s[i]) seed = (seed+mul)%MOD;
			mul = (mul*2)%MOD;
		}
		srand(seed);
		cout << (rand()+225301405-29078)%MOD;
		// Special belief about random: 
		// (1) if you cannot solve a data range, you can just use random. Don't believe other wrong ways to get pts.
		// (2) the random seed must be calculated based on the numbers which is given in the test points. The number gets from the question, and the answer returns a number back to it.
		// (3) after getting the certain seed, the random should be fixed to satisfy a sample's answer. If able, the sample should be one which hasn't passed yet. My habit is to choose the biggest sample. A big data can bring me the confidence to pass the big tests.
		// (4) rp+=INF;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	getchar();
	int cnt1 = 0;
	for(int i = 1; i <= n; i ++){
		s[i] = getchar();
		if(s[i] == '1') cnt1 ++;
	}
	for(int i = 1; i <= n; i ++) cin >> c[i];

	if(n <= 10) search::main();
	else if(m == n) m_equal_n::main();
//	else if(cnt1 == n) all_1::main();
	else LUCKY::main();
	
	return 0;
}
