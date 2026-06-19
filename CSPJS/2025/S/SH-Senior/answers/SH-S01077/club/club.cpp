#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
std::ifstream fin("club.in");
std::ofstream fout("club.out");

std::vector<int> minus[4];

void solve() {
	int n; fin >> n;
	long long ans = 0;
	minus[1].clear(); minus[2].clear(); minus[3].clear();
	for (int i = 1; i <= n; ++i) {
		int a1, a2, a3;  fin >> a1 >> a2 >> a3;
		if (a1 >= a2 && a1 >= a3) {
			ans += a1;
			minus[1].push_back(std::min(a1-a2, a1-a3));
		}
		else if (a2 >= a1 && a2 >= a3) {
			ans += a2;
			minus[2].push_back(std::min(a2-a1, a2-a3));
		}
		else {
			ans += a3;
			minus[3].push_back(std::min(a3-a1, a3-a2));
		}
	}
	int wh = 0;
	for (int i = 1; i <= 3; ++i) if ((int)minus[i].size() > n/2) wh = i;
	if (wh == 0) fout << ans <<"\n";
	else {
		std::sort(minus[wh].begin(), minus[wh].end());
		int cnt = minus[wh].size() - n/2;
		for (int i = 0; i < cnt; ++i) ans -= minus[wh][i];
		fout << ans <<"\n";
	}
}

int main(){
	int t; fin >> t;
	while (t --> 0) {
		solve();
	}
}
