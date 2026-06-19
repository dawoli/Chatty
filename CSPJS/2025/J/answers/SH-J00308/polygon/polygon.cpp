#include<bits/stdc++.h>
using namespace std;

int n , big , sum = 0 , cnt;

int num[5005]; 

int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num[i];
	}
	for(int i = 0 ; i < n ; i++){
		sum = num[i] + num[i + 1] + num[i + 2];
		big = max(num[i] , max(num[i + 1] , num[i + 2]));
		if(sum > big * 2){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
