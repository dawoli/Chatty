#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int p = 131;
const int N = 5e6 + 10;
const int P = 2e5 + 10;
const ull mod = 99824435371;

string s1, s2, st1, st2;
int n, q, ans[P];
ull hash[N], tmp1, tmp2, tmpp1[P], tmpp2[P];

int play(string a){
	hash[0] = a[0];
	for(int i = 1; i < a.size(); i++){
		hash[i] = (hash[i - 1] * p + a[i]) % mod;
	}
	return hash[a.size() - 1];
}

int main(){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> st1 >> st2;
		tmpp1[i] = play(st1);
		tmpp2[i] = play(st2);
	}
	for(int c = 0; c < q; c++){
		cin >> s1 >> s2;
		if(s1.size() != s2.size()){
			continue;
		}
		else{
			tmp1 = play(s1);
			tmp2 = play(s2);
			int cnt = s1.size() - st1.size();
			for(int i = 0; i < n; i++){
				if(tmp1 + tmpp2[i] == tmp2 + tmpp1[i]){
					ans[c]++;
				}
				else{
					for(int k = 0; k <= cnt; k++){
						tmpp1[i] = tmpp1[i] * p % mod;
						tmpp2[i] = tmpp2[i] * p % mod;
						if(tmp1 + tmpp2[i] == tmp2 + tmpp1[i]){
							ans[c]++;
							break;
						}
					}
				}
			}
		}
	}
	
	for(int i = 0; i < q; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}
