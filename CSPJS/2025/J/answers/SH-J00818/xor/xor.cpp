#include<bits/stdc++.h>
using namespace std;
long long n, k, a[500005];
int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	bool f = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] > 255 && a[i] < 0)f = 0;
	}
	if(f){
		if(k > 255)cout << 0 << endl;
		else{
			long long sum = 0, ans = 0, max_ans = -1;
			for(int i = 1; i <= n; i++){
				for(int j = i; j <= n; j++){
					sum ^= a[j];
					if(sum == k) ans++, sum = 0;
				}
				max_ans = max(ans, max_ans);
				ans = 0;
			}
			cout << max_ans << endl;
		}
	} 
	bool ff = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] != 1 && a[i] != 0)ff = 0;
	}
	if(ff){
		if(k > 1)cout << 0 << endl;
		else{
			long long sum = 0, ans = 0;
			for(int i = 1; i <= n; i++){
				sum ^= a[i];
				if(sum == k) ans++, sum = 0;
			}
			cout << ans << endl;
		}
	}
	bool fff = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] != 1)fff = 0;
	}
	if(fff){
		if(k > 1)cout << 0 << endl;
		else if(k == 1)cout << n << endl;
		else if(k == 0)cout << n / 2 << endl;
	}
	if(!f && !ff && !fff){
		long long sum = 0, ans = 0, max_ans = -1;
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				sum ^= a[j];
				if(sum == k) ans++, sum = 0;
			}
			max_ans = max(ans, max_ans);
			ans = 0;
		}
		cout << max_ans << endl;
	}
	return 0;
}

