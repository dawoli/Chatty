#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Ten year's OI all in vain , no long long see forefathers
inline ll read(){
	char c = getchar(); ll t = 0 , f = 1;
	while(c < '0' || c > '9'){if (c == '-') {f = -1;} ; c = getchar();};
	while(c >= '0' && c <='9'){t = t * 10 + c - 48 , c = getchar();}
	return t * f;
}
const int N = 1e5 + 5 , inf = -0x3f3f3f3f;
int T , n , a[5][N] , dp[5005][5005] , cnt , ans;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--){
		memset(dp , -0x3f , sizeof(dp));
		dp[0][0] = 0 , ans = 0 , cnt = 0;
		scanf("%d" , &n); 
		for(int i = 1 ; i <= n ; i++){
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			cnt += a[3][i] , a[1][i] -= a[3][i] , a[2][i] -= a[3][i];
			//cout << "hello\n";
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = i ; j >= 0 ; j--){
				for(int k = i - j ; k >= 0 ; k--){
					if(j > n / 2 || k > n / 2 || (i - j - k) > n / 2){
						dp[j][k] = -inf;continue;
					}
					if(j != 0) dp[j][k] = max(dp[j][k] , dp[j - 1][k] + a[1][i]);
					if(k != 0) dp[j][k] = max(dp[j][k] , dp[j][k - 1] + a[2][i]);
					if(j + k >= n / 2)ans = max(ans , dp[j][k]);
				}
			}
		}
		printf("%d\n" , ans + cnt);
	}
}
