#include <iostream>
#include <vector>
using namespace std;

int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
	return x * f;
}
int l[100005], dp[105][200005];
vector<int> s[100005];
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t = read();
	while (t--){
		int n = read(), k = read(), q = read();
		for (int i = 1; i <= n; i++){
			l[i] = read();
			s[i].resize(l[i])
			for (int j = 1; j <= l[i]; j++)
				s[i][j-1] = read();
		}
		dp[0][1] = -1;
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 2 * 1e5; j++)
				for () 
	}
	return 0;
}
