#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int n,a[5009];
long long zuhe(int m, int get){
	long long res = 1;
	for(int i=0; i<get; i++){
		res *= (m-i);
	}
	while(get >= 1){
		res /= get;
		get--;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int maxa = -1;
	long long tot = 0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		maxa = max(a[i],maxa);
	}
	if(n == 3){
		int l = a[0] + a[1] + a[2];
		int s = max(max(a[0],a[1]),a[2]);
		if(l > s * 2){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}else if(maxa == 1){
		for(int i=3; i<=n; i++){
			tot += zuhe(n,i);
			tot = tot % mod;
		}
	}
	cout << tot % mod << endl;
	return 0;
}

