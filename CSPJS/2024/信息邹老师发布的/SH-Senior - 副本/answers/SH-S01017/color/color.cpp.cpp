#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int main(){
	freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int l,sum=0,maxx=0;
		cin >> l;
		for(int j=0;j<l;j++){
			cin >> a[j];
		}
		for(int k=1;k<n;k++){
			for(int h=0;h<k;h++){
				if(a[k]==a[h]){
					sum += a[k];
				}
			}
		}cout << sum;
	}
	return 0;
}
