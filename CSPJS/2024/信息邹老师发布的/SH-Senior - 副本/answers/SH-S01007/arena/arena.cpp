#include<iostream>
#include<fstream>
#include<string>
std::ifstream fin("arena.in");
std::ofstream fout("arena.out");

long long a[100005];
int c[100005];
std::string s[40];

int main() {
	int n;
	fin >> n;
	int m;
	fin >> m;
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		fin >> c[i];
	}
	int k = 0;
	long long ksm = 1;
	while (n > ksm) {
		ksm *= 2;
		k++;
	}
	for (int i = 1; i <= k; ++i) {
		fin >> s[i];
	}
	int t;
	long long mul[4];
	fin >> t >> mul[0] >> mul[1] >> mul[2] >> mul[3];
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i] ^ mul[i%4];
	}
	for (int i = 1; i <= m;++i) {
	}
	fout << 1;
}
