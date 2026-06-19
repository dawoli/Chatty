#include <iostream>
using namespace std;

int m[55], cnt;

int change(char a[]){
	int x = 0;
	x += (int)a[0] * 128;
	x += (int)a[1];
	return x;
} 

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		char a[3];
		cin >> a;
		int x = change(a);
		m[i] = x; 
		for (int j = 1; j < i; j++){
			if (m[j] == x){
				cnt--;
				break;
			}
		}
		cnt++;
	}
	cout << 52 - cnt;
	return 0;
}
