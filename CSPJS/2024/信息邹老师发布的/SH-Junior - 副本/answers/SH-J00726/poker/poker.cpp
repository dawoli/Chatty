#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n, a[55];
char c;
signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(long long i = 1; i <= 2 * n; ++i){
		cin >> c;
		a[i] = c;
	}
	for(long long i = 1; i <= 2 * n; i+=2){
		for(long long j = i + 2; j <= 2 * n; j+=2){
			if(a[i] + a[i+1]== a[j] + a[j+1]) n -= 1;
		}
	}
	cout << 52 - n;
	return 0;
}
