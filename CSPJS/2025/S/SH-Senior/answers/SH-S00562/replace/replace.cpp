#include<bits/stdc++.h>
const int N = 2e5 + 5;
std::string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int n,q;std::cin >> n >> q;
	for (int i = 1;i <= n;i++) std::cin >> s[i][1] >> s[i][2]; 
	while (q--){
		std::string t1,t2;std::cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1;i <= n;i++){
			int pos = 0 - s[i][1].length();
			while ((pos = t1.find(s[i][1],pos + s[i][1].length())) != -1){
				for (int k = pos,j = 0;j < s[i][2].length();k++,j++) t1[k] = s[i][2][j];
				if (t1 == t2) ++ans;
				for (int k = pos,j = 0;j < s[i][2].length();k++,j++) t1[k] = s[i][1][j];
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}
