#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t, n, a[200005], sum;
	cin >> t;
	for(int i = 1; i <= t; i++){
		sum=0;
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> a[j];
		}
		sort(a, a+n);
		for(int j = 0; j < n; j++){
			if(a[j]==a[j+1]){
				sum+=a[j];
				j++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

