#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
const int mod = 998244353;
bool cmp(int x,int y){
	return x > y;
}
long long ans;
long long f(int x){
	if(x == 1){
		return 1;
	}
	return f(x - 1) * x % mod;
}
long long t(int n,int x){
	return f(n) / (f(x) * f(n - x)) % mod;
}
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	if(n == 3){
		sort(a + 1 , a + n + 1 , cmp);
		int x = a[1];
		int y = a[2];
		int z = a[3];
		if(y + z > x){
			cout << "1"; 
		}else{
			cout << "0";
		}
	}
	for(int i = 3 ; i <= n ; i++){
		ans = ans + t(n,i) % mod;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

//c(n,m) = n ! / (m! * (n - m)!) 
