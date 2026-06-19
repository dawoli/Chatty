#include<bits/stdc++.h>
using namespace std;
long long a[5010];
int main(){
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
	int n , cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1) cnt++;
	}
	if(n == 3){
		sort(a + 1 , a + n + 1);
		if(a[1] + a[2] > a[3]){
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if(cnt == n){
		long long ans = 0;
		for(int i = 0; i <= n - 3; i++){
			long long l = 1;
			for(int j = n; j >= n - i + 1; j--){
				l *= j;
			}
			if(i != 0)l /= i; 
			ans += l;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
