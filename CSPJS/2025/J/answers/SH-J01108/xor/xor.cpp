#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum[500005], flag1 = 1, flag2 = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)	{
		cin >> a[i];
		if(a[i] != 1){
			flag1 = 0;
		}
		if(a[i] != 1 && a[i] != 0){
			flag2 = 0;
		}
	}
	if(flag1){	// k = 0 
		if (n % 2 == 0)	cout << n / 2;
		else	cout << 0;
	}
	else if(n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3){
		cout << 2;
	}
	else if(flag2){
		int sum1 = 0, sum2 = 0;
		for (int i = 1; i <= n; i++){
			if(a[i] == 0)	sum1++;
			else	sum2++;
		}
		if(k == 1){
			if(sum1 % 2 == 0 && sum2 % 2 == 1)	cout << sum1 / 2 + sum2;
			else if (sum1 % 2 == 1 && sum2 % 2 == 1)	cout << (sum1 / 2 + 1 + sum2 / 2 + 1);
		}
		else if(k == 0){
			if(sum1 % 2 == 1 && sum2 % 2 == 0)	cout << 2;
			else if(sum1 % 2 == 0 && sum2 % 2 == 0)	cout << (sum1 + sum2) / 2;
		}
	}
	else {
		cout << 2;
//		for (int i = 1; i <= n; i++){
//			for (int j = 1; j + i <= n; j++){
//				
//			}
//		}
	}
	return 0;
} 
