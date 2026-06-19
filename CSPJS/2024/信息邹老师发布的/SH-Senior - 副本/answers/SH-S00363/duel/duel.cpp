#include<bits/stdc++.h>
using namespace std;
int n, a[100000], amax, c[1000000];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		c[i] = i;
		
	}
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; ++j){
			if(a[i] < a[j]){
				amax = c[i];
				c[i] = c[j];
				c[j] = amax;
			}
		}
	}
//	for(int i = 1; i <= n; ++i){
		
//	}
	for(int i = 1; i <= n; ++i){
		printf("%d", c[i]);
	}
	return 0;
}
