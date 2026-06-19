#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(n <= 2 && k == 0){
		cout << n / 2 << endl;
	}else if(n <= 10 && k <= 1){
		if(k == 0){
			long long tot = 0;
			for(int i=0; i<n; i++){
				if(a[i] == 0){
					tot++;
				}else if(i > 0 && a[i] == 1 && a[i-1] == 1){
					a[i] = 0;
					a[i-1] = 0;
					tot++;
				}
			}
			cout << tot << endl;
		}else{
			long long tot = 0;
			for(int i=0; i<n; i++){
				if(a[i] == 1){
					tot++;
				}
			}
			cout << tot << endl;
		}
	}else if(n <= 100 && k == 0){
		long long tot = 0;
		for(int i=0; i<n; i++){
			if(a[i] == 0){
				tot++;
			}else if(i > 0 && a[i] == 1 && a[i-1] == 1){
				a[i] = 0;
				a[i-1] = 0;
				tot++;
			}
		}
	}else if(n <= 100 && k == 1){
		long long tot = 0;
		for(int i=0; i<n; i++){
			if(a[i] == 1){
				tot++;
			}
		}
		cout << tot << endl;
	}else if(k <= 1){
		if(k == 0){
			long long tot = 0;
			for(int i=0; i<n; i++){
				if(a[i] == 0){
					tot++;
				}else if(i > 0 && a[i] == 1 && a[i-1] == 1){
					a[i] = 0;
					a[i-1] = 0;
					tot++;
				}
			}
		}else{
			long long tot = 0;
			for(int i=0; i<n; i++){
				if(a[i] == 1){
					tot++;
				}
			}
			cout << tot << endl;
		}
	}
	return 0;
}

