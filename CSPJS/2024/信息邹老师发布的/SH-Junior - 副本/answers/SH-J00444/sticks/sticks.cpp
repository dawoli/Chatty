#include<bits/stdc++.h>
using namespace std;
int a[15] = {0,-1,1,7,4,2,6,8,10,18,22,20,28};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n < 13){
			cout << a[n] << "\n";
			continue;
		}
		long long eight = (n-6)/7; 
		long long nn = n-eight*7;
		cout << a[nn];
		for(int i = 0;i < eight;i++){
			cout << "8";
		}
		cout << "\n";
	}
} 
