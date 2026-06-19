#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool choose[5005];

long long check(int i){
	if(i != n){
		long long ans = 0;
		choose[i] = 0;
		ans += check(i+1);
		choose[i] = 1;
		ans += check(i+1);
		return ans;
	}else{
		int sum = 0;
		int max = 0;
		for(int j = 0; j < n; j++){
			if(choose[j]){
				sum += a[j];
				if(a[j] > max){
					max = a[j];
				}
			}
		}
		return sum > (2*max);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	cout << check(0);

	return 0;
}
