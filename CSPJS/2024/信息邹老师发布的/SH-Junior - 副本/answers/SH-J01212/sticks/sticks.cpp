#include <bits/stdc++.h>
using namespace std;
const int num[10] = {6,2,5,5,4,5,6,3,7,6};
const int mnd[10] = {-1,-1,1,7,4,2,6,8,-1,-1}; //min-digit,sticks_num->min_expressed_number
int T,n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		if (n < 8) {
			printf("%d\n",mnd[n]);
			continue;
		}
		if (n % 7 == 0) {
			for (int i = 1; i <= n/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 1) {
			printf("10");
			for (int i = 1; i < (n-1)/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 2) {
			printf("1");
			for (int i = 1; i <= (n-2)/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 3) {
			printf("22");
			for (int i = 1; i < (n-3)/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 4) {
			printf("20");
			for (int i = 1; i < (n-4)/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 5) {
			printf("2");
			for (int i = 1; i <= (n-5)/7; i++) cout << '8';
			puts("");
			continue;
		} else if (n % 7 == 6) {
			printf("6");
			for (int i = 1; i <= (n-6)/7; i++) cout << '8';
			puts("");
			continue;
		}
	}
	return 0;
}
