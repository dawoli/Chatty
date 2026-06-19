#include<bits/stdc++.h>
using namespace std;
int a[105] , n , m , L , ans1 , ans2;
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	int c = n * m;
	cin >> a[0];
	L = a[0];
	for(int i = 1;i < n * m;i ++){
		cin >> a[i];
	}
	sort(a , a + c - 1 , cmp);
	for(int i = 0;i < n * m;i ++){
		if(a[i] == L){
			L = i + 1;
			break;
		}
	}
	ans1 = L / n;
	L = L - ans1 * n;
	if(L) {
		ans1 ++;
		ans2 = L;
		if(ans1 % 2 == 0) ans2 = n - ans2 + 1;
	}
	else{
		if(ans1 % 2 == 0) ans2 = 0;
		else ans2 = n;
	}
	cout << ans1 << ' ' << ans2;
}
