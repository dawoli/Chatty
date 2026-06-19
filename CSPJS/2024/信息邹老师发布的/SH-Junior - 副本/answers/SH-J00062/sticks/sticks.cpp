#include<bits/stdc++.h>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6};
int n;

int whi(int n) {
	int ans = 0;
	while(n) {
		ans += a[n % 10];
		n /= 10; 
	}
	return ans;
}

int ret(int n) {
	for(int i = 0;;i++)
		if(whi(i) == n)
			return i;
}

int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&n);
	for(int j = 1;j <= n;j++) {
		int x;
		scanf("%d",&x);
		if(x < 2) {
			printf("-1\n");
			continue;
		}
		if(x % 7 == 0) {
			for(int i = 1;i <= x / 7;i++)
				printf("8");
			printf("\n");
			continue;
		}
		if((x - 1) % 7 == 0) {
			printf("10");
			for(int i = 1;i <= (x - 1) / 7 - 1;i++)
				printf("8");
			printf("\n");
			continue;
		}
		printf("%d\n",ret(x));
	} 
}
