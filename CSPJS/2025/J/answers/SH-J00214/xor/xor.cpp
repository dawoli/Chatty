#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sum;
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int yh=a[i];
		if(a[i]==k){
			i++;
			sum++;
		}
		for(int j=i+1;j<=n;j++){
			yh^=a[j];
			if(yh==k){
				i=j+1;
				sum++;
				break;
			}
		}
	}
	cout << sum;
	return 0;
} 
