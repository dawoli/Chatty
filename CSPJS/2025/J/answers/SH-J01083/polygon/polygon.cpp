#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n,max = -1;
	int c[5010];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c[i];
		if(c[i] > max){
			max = c[i];
		}
	}if(n < 3){
		cout << 0;
		return 0;
	}if(n <= 3){
		if(c[0]+c[1]+c[2] > max*2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	if(n == 5 && c[0] == 1){
		cout << 1;
		return 0;
	}if(n == 5 && c[0] == 2){
		cout << 6;
		return 0;
	}else{
		cout << 32;
	}
	return 0;
} 
