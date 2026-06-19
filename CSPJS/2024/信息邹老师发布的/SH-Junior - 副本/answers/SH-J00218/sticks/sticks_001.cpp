#include<bits/stdc++.h>
using namespace std;
int T,n;
int st[10] = {6,2,5,5,4,5,6,3,7,6};
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		if(n <= 50) {
			int s = n / 7; 
			if(n % 7 != 0) {
				s ++;
			}
			if(n == 1) {
				printf("-1\n");
			}else {
				for(int i = pow(10,s - 1);;i = i + 1) {
					int t = i,ans = 0;
					while(t > 0) {
						int d = t % 10;
						ans += st[d];
						t /= 10;
					}
					if(ans == n) {
						printf("%d\n",i);
						break;
					}
					if(ans > 11000000) {
						printf("-1\n");
						break;
					}
				}
				
			}
		}
		else {
			int tmp = n % 7,tmpp = n / 7;
			if(tmp == 1) {
				printf("10");
				tmpp --;
			}else if(tmp == 2) {
				printf("1");
			}else if(tmp == 3) {
				printf("200");
				tmpp -= 2;
			}else if(tmp == 4) {
				printf("20");
				tmpp --;
			}else if(tmp == 5) {
				printf("2");
			}else if(tmp == 6) {
				printf("6");
			}
			for(int i = 1;i <= tmpp;i = i + 1) {
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
