#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;scanf("%d",&t);
	while (t--) {
		int n,ct8;scanf("%d",&n),ct8=n/7;
		if (ct8*7==n) {
			while (ct8--) putchar('8');
			putchar('\n');
		}else if (n%7==1) {
			if (n==1) puts("-1");
			else {
				putchar('1'),putchar('0'),ct8--;
				while (ct8--) putchar('8');
				putchar('\n');
			}
		}else if (n%7==2) {
			putchar('1');
			while (ct8--) putchar('8');
			putchar('\n');
		}else if (n%7==3) {
			if (n==3) puts("7");
			else if (n==10) puts("22");
			else {
				putchar('2'),putchar('0'),putchar('0'),ct8-=2;
				while (ct8--) putchar('8');
				putchar('\n');
			}
		}else if (n%7==4) {
			if (n==4) puts("4");
			else {
				putchar('2'),putchar('0'),ct8--;
				while (ct8--) putchar('8');
				putchar('\n');
			}
		}else if (n%7==5) {
			putchar('2');
			while (ct8--) putchar('8');
			putchar('\n');
		}else if (n%7==6) {
			putchar('6');
			while (ct8--) putchar('8');
			putchar('\n');
		}
	}
	return 0;
}
