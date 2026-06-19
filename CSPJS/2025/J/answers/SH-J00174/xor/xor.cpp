#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int N = 5e5+10;
long long n,k;
long long a[N];
bool f[N];
long long ans = 0;

int main(){
    freopen64("xor.in","r",stdin);
	freopen64("xor.in","r",stdin);
	freopen64("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		if (a[i] == k){
			f[i] = 1;
			ans++;
		}
	}
	int last = n+10;
	for (int i = 1;i <= n;i++){
		if (f[i]) continue;
		if (i >= last){
			ans++;
			last = n+10;
		}
		long long j = i+1;
		long long sum = a[i];
		while (!f[j] && j <= n && i != n){
			sum = sum^a[j];
			if (sum == k){
				if (j < last){
					last = j;
					//cout << i << " " << j << " " << sum << endl;
				}
				break;
			}
			j++;
			//cout << j << " " << sum << endl;
		}
		
	}
	cout << ans << endl;
	return 0;
}
