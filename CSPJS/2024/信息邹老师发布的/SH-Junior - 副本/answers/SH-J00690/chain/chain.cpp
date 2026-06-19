#include <bits/stdc++.h>
using namespace std;
int t, n, k, q, r, c;
vector<int> s[100005];

bool dfs(int rs, int lc, int lp){
//	printf("%d\t%d\t%d\n", rs, lc, lp);
	if(rs <= 0) return (lc == c);
	for(int i = 1; i <= n; i ++)
		if(i != lp)
			for(int j = 0; j < s[i].size(); j ++)
				if(rs == r && s[i][j] == 1 || s[i][j] == lc)
					for(int l = 1; l < k && j + l < s[i].size(); l ++)
						if(dfs(rs - 1, s[i][j + l], i))
							return 1;
	return 0;
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n >> k >> q;
		for(int i = 1; i <= n; i ++){
			s[i].clear();
			cin >> r;
			for(int j = 1; j <= r; j ++){
				cin >> c;
				s[i].push_back(c);
			}
		}
		while(q --){
			cin >> r >> c;
			if(r == 1){
				bool f = 0;
				for(int i = 1; i <= n; i ++)
					for(int j = 0; j < s[i].size() - 1; j ++)
						if(s[i][j] == 1)
							for(int l = 1; l < k && j + l < s[i].size(); l ++)
								if(s[i][j + l] == c){
//									printf("%d %d %d %d %d %d | ", i, j, l, s[i][j], s[i][j + l], s[i].size());
									f = 1;
								}
				cout << f << endl;
			}
			else cout << dfs(r, 0, 0) << endl;
		}
	}
	return 0;
}
