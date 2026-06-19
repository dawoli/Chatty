#include<bits/stdc++.h>
using namespace std;
long long a[110];
bool cmp(long long x , long long y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	for(long long i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	long long little_A_score = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(long long i = 1; i <= n * m; i++){
		if(a[i] == little_A_score){
			if(i % n != 0){
				cout << i / n + 1 << " ";
				if((i / n + 1) % 2 == 1){
					cout << i % n << endl;
				} else {
					cout << n - i % n + 1 << endl;
				}
			} else {
				cout << i / n << " ";
				if((i / n) % 2 == 1){
					cout << n << endl;
				} else {
					cout << 1 << endl;
				}
			}
			return 0;
		}
	}
	return 0;
} 
