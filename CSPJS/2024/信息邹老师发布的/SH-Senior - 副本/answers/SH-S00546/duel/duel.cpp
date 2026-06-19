#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
std::fstream fin("duel.in");
std::fstream fout("duel.out");

int n;
const int maxn = 100010;
long long r[maxn];



int main(){
	fin >> n;
	for (int i=0; i < n; ++i) {
		fin >> r[i];
	}
	std::sort(r, r + n);
//	std::multiset<int> f;
//	for (int i=0; i < n; ++i) {
//		f.insert(r[i]);
//	}
	int ct = 0;
//	for (auto i = *(std::upper_bound(r, r+n, ct)); i != r+n; i = *(std::upper_bound(r, r+n, ct)), ct++) {
//		//114514
//		
//	}
	for (int i=0; i < n; ++i) {
		if (r[i] > r[ct]) ct++;
	}
//	std::cout << n - ct;
	fout << n - ct;
	return 0;
	
}
