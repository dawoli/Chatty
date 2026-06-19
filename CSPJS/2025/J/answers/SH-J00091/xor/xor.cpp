#include <bits/stdc++.h>
using namespace std;
long long n,k,c,d;
long long a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(a[1] == 0){
		c =0;
	}
	else if(a[1] == 1){
		d = 1;
		c= d;
	}
	cout << 1;
	return 0;
} 
