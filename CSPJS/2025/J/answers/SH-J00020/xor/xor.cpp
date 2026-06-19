#include <bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 5e5 + 10;
int a[maxn];
int main(){
	freopen("xor.in" , "r"  ,stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	bool f = true,f1 = true;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] != 1){
			f = false;
		}else if(a[i] > 1){
			f1 = false;
		}
	}
	if(f == true && k == 0){
		cout << n / 2;
	}else if(f1 == true){
		int sum = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[i] == 1){
				sum ++;
			}
		}
		if(k == 1){
			cout << sum;
		}else if(k == 0){
			int sum1 = sum / 2;
			int sum2 = 0;
			for(int i = 1 ; i <= n ; i++){
				if(a[i] == 0){
					sum2 ++;
				}
			}
			int ans = max(sum2 , sum1);
			for(int i = 1 ; i < n ; i++){
				if(a[i] == 1 && a[i + 1] == 1){
					ans ++;
					a[i + 1] = 0;
				}
			}
			cout << ans;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
