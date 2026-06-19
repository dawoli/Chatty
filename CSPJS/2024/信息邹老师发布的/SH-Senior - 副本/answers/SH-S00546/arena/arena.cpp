#include <bits/stdc++.h>

std::fstream fin("arena.in");
std::fstream fout("arena.out");


int main() {
	int T;
	fin >> T;
	while(T --> 0) {
		fout << rand() % 100;
	}
	return 0;
}
