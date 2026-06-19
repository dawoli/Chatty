#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0;
	int a[1005];
	cin >> n >> k;
	for(int i = 0; i <= n; i++){
		cin >> a[i];
		if(a[i] == 1)cnt++;
	}
	cout << cnt;
	return 0;
}
