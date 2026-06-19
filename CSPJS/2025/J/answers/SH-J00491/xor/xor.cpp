#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n , k , a[N] , ans = 0;
void ifanser(int p , int q){
	int cnt = a[p];
	for(int i = p + 1;i <= q;i ++){
		cnt = cnt ^ a[i];
	}
	if(cnt == k) ans ++;
	return;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 0;i < n;i ++){
		cin >> a[i];
		if(a[i] == 2) ans ++;
	}
	for(int i = 0;i < n;i ++){
		for(int j = i + 1;j < n;j ++){
			ifanser(i , j);
		}
	}
	cout << ans;
	return 0;
} 
