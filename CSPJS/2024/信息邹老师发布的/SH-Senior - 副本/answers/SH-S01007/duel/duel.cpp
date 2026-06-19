#include<iostream>
#include<fstream>
#include<algorithm>
std::ifstream fin("duel.in");
std::ofstream fout("duel.out");

int a[100005];
int cnt[100005];

int main() {
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i){
		fin >> a[i];
		cnt[a[i]]++;
	}
	std::sort(a+1, a+n+1);
	int low = 0;
	int beaten = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > a[i-1]) {
			low  += cnt[a[i-1]];
		}
		if (low > 0) {
			beaten++;
			low--;
		}
	}
	fout << n-beaten;
}
