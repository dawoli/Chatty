#include <bits/stdc++.h>

std::fstream fin("color.in");
std::fstream fout("color.out");

long long n;
const int maxn = 200020;
long long a[maxn];

int color[maxn]; //
int lastf;
int lastt;

long long answer;
long long best;
void brute(int i) {
	if (i == n) {
		best = std::max(best, answer);
		return;
	}
	color[i] = 11;
	bool asv = lastt != -1 and a[lastt] == a[i];
	if (asv) answer += a[i];
	lastt = i; 
	brute(i + 1);
	if (asv) answer -= a[i];	
	color[i] = 22;
	asv = lastf != -1 and a[lastf] == a[i];
	if (asv) answer += a[i]; 
	lastf = i;
	brute(i + 1);
	if (asv) answer -= a[i];
}

void solve() {
	fin >> n;
	lastf = lastt = -1;
	answer = best = 0;
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
		color[i] = 0; 
	}
	if (n <= 15) {
//		std::cout << "@";
		brute(0);
		fout << best << '\n';
		std::cout << best << '\n';
	}
}

int main() {
//	int a = 1;
//	for (int i=0; i<15; ++i) a *= 2;
//	std::cout <<a;
	int T;
	fin >> T;
	while (T --> 0) solve();
	return 0;
}
