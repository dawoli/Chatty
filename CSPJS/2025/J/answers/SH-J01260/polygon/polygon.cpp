#include<bits/stdc++.h>

using namespace std;

int arr[10005];
int long long sum = 0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	int cnt = 0;
	for(int i = 0;i < n;i++){
		sum += arr[i];
	}
	cout << sum % 998244353;
	return 0;
} 









