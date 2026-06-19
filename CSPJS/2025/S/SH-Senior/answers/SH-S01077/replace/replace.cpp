#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("replace.in");
std::ofstream fout("replace.out");

std::vector<int> nxt1[200005], nxt2[200005];
std::string ss1[200005], ss2[200005];

int main(){
	int n, q; fin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::string s1, s2; fin >> s1 >> s2;
		ss1[i] = s1, ss2[i] = s2;
		int m = s1.size();
		nxt1[i].push_back(-1); nxt1[i].push_back(0);
		for (int j = 2; j <= m; ++j) {
			int last = nxt1[i][j-1];
			while (last != -1 && s1[last] != s1[j-1]) last = nxt1[i][last];
			nxt1[i].push_back(last+1);
		}
		nxt2[i].push_back(-1); nxt2[i].push_back(0);
		for (int j = 2; j <= m; ++j) {
			int last = nxt2[i][j-1];
			while (last != -1 && s2[last] != s2[j-1]) last = nxt2[i][last];
			nxt2[i].push_back(last+1);
		}
	}
	for (int i = 1; i <= q; ++i) {
		std::string t1, t2; fin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			fout << 0 <<"\n";
			continue;
		}
		int mini = 1e9, maxi = -1;
		for (int j = 0; j <(int)t1.size(); ++j) {
			if (t1[j] != t2[j]) {
				mini = std::min(mini, j); maxi = std::max(maxi, j);
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; ++j) {
			if ((int)nxt1[j].size()-1 < maxi - mini + 1) continue;
			int start = maxi - (int)nxt1[j].size() + 1, end = mini + nxt1[j].size()-1;
			int now1 = 0, now2 = 0;
			for (int k = std::max(0,start); k <= std::min((int)t1.size()-1,end); ++k) {
				while (now1 != -1 && ss1[j][now1] != t1[k]) now1 = nxt1[j][now1];
				now1++;
				while (now2 != -1 && ss2[j][now2] != t2[k]) now2 = nxt2[j][now2];
				now2++;
				if (now1 == now2 && now1 == (int)ss1[j].size()) {
					ans++;
				}
			} 
		}
		fout << ans <<"\n";
	}
}
