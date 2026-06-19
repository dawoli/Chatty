#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T;
int n, A[maxn];
int dp[maxn];
int prevOccurance[maxn], prevIndex[maxn];

int cal(int l, int r){
	int c = 0;
	for (int i = l + 1; i <= r; i++){
		if (prevIndex[A[i]] != -1){
			if (prevIndex[A[i]] < l || prevIndex[A[i]] > r){
			    c += A[i];
		    }
		}
		else{
			c += A[i] * (A[i] == A[i - 1]);
		}
	}
	return c;
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    cin >> T;
    for (int _ = 0; _ < T; _++){
    	cin >> n;
    	memset(prevOccurance, -1, sizeof(prevOccurance));
    	memset(prevIndex, -1, sizeof(prevIndex));
    	for (int i = 0; i < n; i++){
    		cin >> A[i];
    		if (prevOccurance[A[i]] != -1){
    			prevIndex[i] = prevOccurance[A[i]];
			}
			prevOccurance[A[i]] = i;
		}
		dp[0] = 0;
		for (int i = 1; i < n; i++){
			if (prevIndex[i] != -1){
				// has prev
				dp[i] = max(dp[i - 1], dp[prevIndex[i] - 1] + cal(prevIndex[i] + 1, i - 1) + A[i]);
			}
			else{
				dp[i] = dp[i - 1];
			}
		}
		cout << dp[n - 1] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
