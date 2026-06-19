#include<bits/stdc++.h>
using namespace std;
#define ll long long
//ten year's OI all in vain , no long long see forefathers
int T , n , k , q , li , si , r , c;
int s[200005] , l[100005] , sl[100005];
int dp[105][200005];  // -1  i  0
void init(){
	for(int II = 1 ; II <= 100 ; II++){
		int lk = 1;
		for(int i = 0 ; i < sl[n] ; i++){
			if(i >= sl[lk]) lk++;
			if(dp[II - 1][s[i]] == 0 || (dp[II - 1][s[i]] != -1 && dp[II - 1][s[i]] != lk)){
				for(int j = i + 1 ; j < i + k && j < sl[lk] ; j++){
					if(dp[II][s[j]] == -1 || dp[II][s[j]] == lk){
						dp[II][s[j]] = lk;
					}
					else{
						dp[II][s[j]] = 0;
					}
				}
			}
		}
	}
}
int main(){
	freopen("chain.in" , "r" , stdin);
	freopen("chain.out" , "w" , stdout);
	cin >> T;
	for(int I = 0 ; I < T ; I++){
		memset(dp , -1 , sizeof(dp));
		dp[0][1] = 0;
		cin >> n >> k >> q;
		for(int i = 1 ; i <= n ; i++){
			cin >> l[i];
			sl[i] = l[i] + sl[i - 1];
			for(int j = 0 ; j < l[i] ; j++){
				cin >> s[sl[i - 1] + j];
			}
		}
		//cout << "step1ok\n";
		init();
		for(int i = 0 ; i < q ; i++){
			cin >> r >> c;
			cout << (dp[r][c] != -1) << "\n";
		}
	}
}
