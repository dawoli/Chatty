#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005], num;
int x = 1, y = 1;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	} 
	int k = a[1];
	sort(a+1, a + 1 + n * m, cmp);
	int flag = 0;
	for(int i = 1; i <= n * m; i++){
		if(k == a[i]){
			cout << y << " " << x;
			return 0;
		}
		if((flag == 0 && x == n) || (flag == 1 && x == 1)){
			y ++;
			if(y % 2 == 0) {
				x = n;
				flag = 1;
			}
			else {
				x = 1;
				flag = 0;
			}
		} 
		else {
			if(flag == 0) x++;
			if(flag == 1) x--;
		}
	}
	return 0;
}
