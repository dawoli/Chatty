#include <bits/stdc++.h>

using namespace std;

void submain() {
	int N;
	cin >> N;
	int M = N / 2;
	vector<int> A1(N + 1), A2(N + 1), A3(N + 1);
	int SUMA1 = 0, SUMA2 = 0, SUMA3 = 0;
	for(int i = 1; i <= N; i++) {
		cin >> A1[i] >> A2[i] >> A3[i];
		SUMA1 += A1[i];
		SUMA2 += A2[i];
		SUMA3 += A3[i];
	}
	if(SUMA1 && SUMA2 && SUMA3) {
		vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(M + 1, vector<int>(M + 1)));
		for(int i = 1; i <= N; i++) {
			for(int j = M; j >= 0; j--) {
				for(int k = M; k >= 0; k--) {
					for(int l = M; l >= 0; l--) {
						if(j - 1 >= 0) {
							dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l] + A1[i]);
						}
						if(k - 1 >= 0) {
							dp[j][k][l] = max(dp[j][k][l], dp[j][k - 1][l] + A2[i]);
						}
						if(l - 1 >= 0) {
							dp[j][k][l] = max(dp[j][k][l], dp[j][k][l - 1] + A3[i]);
						}
					}
				}
			}
		}
		cout << dp[M][M][M] << '\n';
	}
	else if(SUMA1 && SUMA2) {
		vector<vector<int>> dp(M + 1, vector<int>(M + 1));
		for(int i = 1; i <= N; i++) {
			for(int j = M; j >= 0; j--) {
				for(int k = M; k >= 0; k--) {
					if(j - 1 >= 0) {
						dp[j][k] = max(dp[j][k], dp[j - 1][k] + A1[i]);
					}
					if(k - 1 >= 0) {
						dp[j][k] = max(dp[j][k], dp[j][k - 1] + A2[i]);
					}
				}
			}
		}
		cout << dp[M][M] << '\n';
	}
	else if(SUMA1) {
		vector<int> dp(M + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = M; j >= 0; j--) {
				if(j - 1 >= 0) {
					dp[j] = max(dp[j], dp[j - 1] + A1[i]);
				}
			}
		}
		cout << dp[M] << '\n';
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while(T--) {
		submain();
	}
	return 0;
}
