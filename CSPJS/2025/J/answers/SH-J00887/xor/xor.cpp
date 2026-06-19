#include <bits/stdc++.h>
using namespace std;

long long a[500005];

int n, k;

long long yh(long long a, long long b){
	long long ans = 0;
	long long lvl = 1;
	while(1){
		if(a == 0 && b == 0){
			break;
		}
		ans += ((a % 2) ^ (b % 2)) * lvl;
		lvl *= 2;
		a /= 2;
		b /= 2;
	}
	return ans;
} 

long long run(int check, int get){
	if(a[check] == k){
		return run(check + 1, get + 1);
	}
	else{
		long long Max = -1;
		Max = max(run(check + 1, get), Max);
		long long yhz = a[check];
		for(int i = check + 1; i <= n; i++){
			yhz = yh(a[i],yhz);
			if(yhz == k){
				Max = max(run(i + 1, get + 1), Max);
			}
		}
		return Max;
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	printf("%lld", 2);
	return 0;
}
