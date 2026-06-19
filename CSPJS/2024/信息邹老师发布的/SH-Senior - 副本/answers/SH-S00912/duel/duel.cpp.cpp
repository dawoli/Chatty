#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, a[100005], f=1, num=0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort (a, a+n);
	for(int i = 0; i < n; i++){
		if(a[i]==a[i+1]){
			f++;
		}
		else{
			num+=min(f, n-i-1);
			f=1;
		}
	}
	cout<< n-num;
	return 0;
} 
