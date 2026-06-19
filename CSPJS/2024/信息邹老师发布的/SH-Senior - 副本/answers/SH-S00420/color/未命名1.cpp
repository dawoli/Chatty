#define mp(x, y) make_pair(x, y)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int T;
int n;
ll a[N], dp[N];


int main(){
	freopen("color1.in", "r", stdin);
	cin>> T;
	while(T--){
		memset(a, 0 ,sizeof(a));
		memset(dp, 0, sizeof(dp));
		cin>> n;
		for(int i = 1; i <= n; i++)
			cin>> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i - 1; j >= 1; j--){
				if(a[i] == a[j]){
					if(i - j > 3)
						dp[i] = max(dp[j] + a[i], dp[i - 1]);
					else
						dp[i] = dp[j] + a[i];
				}
				else
					dp[i] = max(dp[i], dp[i - 1]);
			}
		}
		//for(int i = 1; i<= n; i++)
			cout<< dp[n]<< endl;
	}
	return 0; 
}
