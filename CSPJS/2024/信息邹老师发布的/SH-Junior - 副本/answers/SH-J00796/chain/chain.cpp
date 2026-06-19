#include<bits/stdc++.h>
using namespace std;
int T, n, k, q, flag;
vector<int> dic[100002];
vector<pair<int, int>> vris[200002];
void dfs(int r, int ed, int lst, int dest){
	//cout << r << ' ' << ed << ' ' << lst << ' ' << dest << ' ' << flag << endl;
	if(r == 0){
		if(dest == ed)
			flag = 1;
		return;
	}
	int i, j, sz;
	for(pair<int, int> p : vris[ed]){
		i = p.first, j = p.second;
		if(i == lst)
			continue;
		sz = dic[i].size();
		for(int l = 1; l < k && j + l < sz; ++l){
			dfs(r - 1, dic[i][j + l], i, dest);
			if(flag == 1)
				return;
		}
	}
}
int main(){
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, tmp, r, c;
	cin >> T;
	while(T--){
		cin >> n >> k >> q;
		memset(dic, 0, sizeof(dic));
		memset(vris, 0, sizeof(vris));
		for(int i = 1; i <= n; ++i){
			cin >> l;
			for(int j = 1; j <= l; ++j){
				cin >> tmp;
				dic[i].push_back(tmp);
				vris[tmp].push_back(make_pair(i, j - 1));
			}
		}
		for(int i = 1; i <= q; ++i){
			flag = 0;
			cin >> r >> c;
			dfs(r, 1, 0, c);
			cout << flag << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

