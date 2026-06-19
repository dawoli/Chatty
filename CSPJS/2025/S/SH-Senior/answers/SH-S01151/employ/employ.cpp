#include<fstream>
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
std::ifstream fin ("employ.in" );
std::ofstream fout("employ.out");
int M = 998244353; 
int n, m; 
bool status[520]; 
int c[520]; 

bool check(std::vector<int> a) {
	int reject = 0; 
	for (int i = 0; i < n; i++) {
		// if too hard, reject
		if (!status[i]) reject++; 
		else {
			// else look at patience
			if (c[a[i]] > reject) ;
			else reject++; 
		}
	}
	// accepted is n - reject
	return (n - reject) >= m; 
}

int count[520]; 
int pref[520]; 

int main() {
	fin >> n >> m; 
	std::string s; fin >> s; 
	int ccount = 0; 
	for (int i = 0; i < n; i++) {
		status[i] = (s[i] == '1'); 
		if (status[i]) ccount++; 
	}
	bool flag = false; 
	for (int i = 0; i < n; i++) {
		fin >> c[i]; 
		if (c[i] == 0) flag = true; 
	}
	if (m > ccount) {
		fout << 0; 
		return 0; 
	}
	
	std::vector<int> a(n); 
	for (int i = 0; i < n; i++) a[i] = i; 
	ll total = 1; 
	for (int i = 1; i <= n; i++) {
		total *= i; 
		total %= M; 
	}
	if (m == n) {
		if (flag) {fout << 0; return 0; }
		else {fout << total; return 0; }
	}
	
	if (m == 1) {
		for (int i = 0; i < n; i++) 
			count[c[i]]++; 
		for (int i = 0; i <= n; i++) 
			pref[i+1] = pref[i] + count[i]; 
		ll rem = 1;  
		int qwe = 0; 
		for (int i = 0; i < n; i++) {
			if (status[i]) {
				// want reject, 
				// so need person with patience <= i
				// which is to say, < i+1
				rem *= (pref[i+1] - qwe); 
				rem %= M; 
				qwe++; 
			}
		}
		int final = n - qwe; 
		for (int i = 1; i <= final; i++) {
			rem *= i; 
			rem %= M; 
		}
		fout << ( (total - rem) % M + M) % M;
	
	
	
	
	
		return 0; 
	}
	if (n > 10) {
		fout << 0; return 0; 
	}
	
	int sum = 0;
	for (int i = 0; i < total; i++) {
		if (check(a)) sum++; 
		std::next_permutation(a.begin(), a.end()); 
	}
	fout << sum; 
}
