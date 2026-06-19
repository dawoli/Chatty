#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n, m, tar, k;
int a[N * N + 10];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	tar = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i] == tar){
			k = i;
			break;
		}
	}
	int a = k / n, b = k % n;
	int c, r;//cÁÐrÐÐ 
	if(a & 1){//ÆæÊý 
		if(b){
			c = a + 1;
			r = n - b + 1;
		}else{
			c = a;
			r = n;
		}
	}else{
		if(b){
			c = a + 1;
			r = b;
		}else{
			c = a;
			r = 1;
		}
	}
	cout << c << " " << r << endl;
	return 0;
}
