#include<bits/stdc++.h>

using namespace std;

int arr[50005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	cout << arr[n-2];
	return 0;
} 









