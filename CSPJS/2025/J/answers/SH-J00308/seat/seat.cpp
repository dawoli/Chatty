#include<bits/stdc++.h>
using namespace std;

int n , m , k , l = 1 , p = 1;

int num[105];

bool cmp(int a , int b){
	return a > b;
}

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 0 ; i < n * m  ; i++){
		cin >> num[i];
	}
	k = num[0];
	sort(num , num + n * m , cmp);
	for(int i = 0 ; i < n * m ; i++){
		if(num[i] == k){
			cout << l << ' ' << p;
			break;
		}
		
		if((l - 1) % 2 == 0){
			if(p == n){
				l++;
				p--;
			}
			p++; 
		}
		else{
			if(p == 1){
				l++;
				p++;
			}
			p--;
		}
	}
	return 0;
}
