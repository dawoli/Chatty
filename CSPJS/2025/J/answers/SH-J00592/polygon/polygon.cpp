#include<bits/stdc++.h>
using namespace std;

const int N = 5000;
int n;
int a[5000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	int sum_ = 0, maxn = 0;
	if (n==3){
		for (int i = 0; i < n; i++){
			sum_ += a[i];
			maxn = max(maxn, a[i]);
		}
		if (sum_ > maxn*2){
			cout << 1 << endl;
			return 0;
		}
		cout << 0 << endl;
		return 0;
	} else{
		for (int i = 3; i <= n; i++){
			cout << i << endl;
			for (int k = 0; k <= n-i; k++){
				int sum2 = 0, maxn2 = 0;
				for (int j = k; j < k+i; j++){
					sum2 += a[j];
					maxn2 = max(maxn2, a[j]);
				}
				if (sum2 > maxn2*2){
					sum_ += 1;
				}
			}
			
			cout << sum_ << endl;
		}
		
		cout << sum_ << endl;
		return 0; 
	}
	
	return 0;
}
