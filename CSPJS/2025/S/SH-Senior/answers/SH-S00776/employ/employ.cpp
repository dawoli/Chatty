#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353; 
int n,m,patience[504];
string s;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++){
		cin >> patience[i];
	}
	if(n <= 10){
		int ans = 0;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			v[i] = i;
		}
		do{
			int dead = 0;
			for(int i = 0; i < n; i++){
				if(dead >= patience[v[i]] || s[i] == '0'){
					dead++;
				}
			}
			if(dead <= n - m){
				ans++;
			}
		}while(next_permutation(v.begin(),v.end()));
		cout << ans;
	}
	return 0;
}  
