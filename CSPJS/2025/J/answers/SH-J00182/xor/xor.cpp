#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N] , c[N];
struct baby{
	int s;
	bool f;
};
long long n , k;
baby check(int start , int end){
	baby a;
	a.f = false;
	a.s = end;
	for(int i = start + 1; i <= end - 1; i++){
		for(int j = i; j <= end - 1; j++){
			if((c[j] ^ c[i - 1]) == k){
				a.s = j;
				a.f = true;
				return a;
			}
		}
	}
	return a;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		c[i] = a[i] ^ c[i - 1];
	}
	long long s = 1 , cnt = 0;
	for(int i = 1; i <= n; i = s){
		bool flag = true;
		for(int j = i; j <= n; j++){
			if((c[j] ^ c[i - 1]) == k){
				flag = false;
				cnt++;
				s = j + 1;
				while(check(i , s).f){
					s = check(i , s).s;
				}
				break;
			}
		}
		if(flag){
			s++;
		}
	}
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
