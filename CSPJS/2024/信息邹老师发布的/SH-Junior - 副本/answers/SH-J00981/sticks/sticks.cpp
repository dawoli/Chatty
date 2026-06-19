#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
const long long MAX_LL = (2ll<<62ll)-2ll+(2ll<61ll);
int sticks_cnt[10] = {6,2,5,5,4,5,6,3,7,6};
long long dp[10002] = {-1,-1,1,7,4,3,6,8,10};
int Ts[52];
char i2a_cache[20];
char* sticks__i2a(long long n, char* cache = i2a_cache) {
	bool neg = false;
	if (n < 0) { neg = true; n = -n; }
	char temp[50] = {};
	int c = 49;
	while (n != 0) {
		temp[c--] = char(n%10+'0');
		n /= 10;
	}
	if (neg) temp[c--]='-';
	for (int i = 0; i < 50; i++) cache[i] = temp[i];
	return cache;
}
int sticks_len(char* cache) {
	int c;
	for (c = 49; c > 0; c--) if (cache[c] == 0) break;
	return 49-c;
}
char* sticks_normal(char* cache) {
	int c = 50-sticks_len(cache);
	char temp[50]; for (int i = 0; i < 50; i++) temp[i] = cache[i];
	for (int i = c; i < 50; i++) cache[i-c] = temp[i];
	cache[50-c] = 0;
	return cache;
}

std::string sticks_i2a(long long n) {
	char temp[50];
	sticks_normal(sticks__i2a(n, temp));
	return temp;
}

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	scanf("%d", &T);
	int mx = 0;
	for (int ti = 0; ti < T; ti++) {
		scanf("%d", &Ts[ti]);
		if (Ts[ti] > mx) mx = Ts[ti];
	}
	for (int i = 9; i <= mx; i++) {
		long long mn = MAX_LL;
		for (int j = i-7; j <= i-2; j++) {
			long long base_num = dp[j];
			long long add_num = dp[i-j];
			base_num = base_num*10+add_num;
			std::string base = sticks_i2a(base_num);
			
			for (int i = 0; i < base.size(); i++) {
				if (base[i] == '3' ||
					base[i] == '5') base[i] = '2';
			}
			int cnt = 0;
			for (int i = 0; i < base.size(); i++) {
				if (base[i] == '6' ||
					base[i] == '9') continue;
				cnt++;
			}
			std::string base2 = base;
			if (cnt) {
				for (int i = 0; i < base.size(); i++) {
					if (base[i] == '6' ||
						base[i] == '9') base[i] = '0';
				}
			}
			std::sort(base.begin(), base.end());
			if (base[0] == '0') {
				for (int i = 0; i < base.size(); i++) {
					if (base[i] != '0') {
						base[0] = base[i];
						base[i] = '0';
						break;
					}
				}
			}
			
			base_num = std::atoi(base.c_str());
			long long base_num2 = std::atoi(base2.c_str());
			if (base_num2 < mn) mn = base_num2;
			if (base_num < mn) mn = base_num; 
		}
		dp[i] = mn;
	}
	for (int ti = 0; ti < T; ti++) {
		printf("%lld\n", dp[Ts[ti]]);
	}
	return 0;
}
