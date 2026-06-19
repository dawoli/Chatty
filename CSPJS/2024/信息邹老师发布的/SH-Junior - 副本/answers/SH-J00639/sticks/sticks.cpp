#include<bits/stdc++.h>

using namespace std;
//2 5, 5 4 5 6 3 7 6 6,
//1 2, 3 4 5 6 7 8 9 0,
int ans = 100005, asn[100005], t, n, a[100005], sum, yu[9] = {-1, -1, 1, 7, 4, 2, 0, 8};

bool cvb(){
	if(sum > ans){
		return false;
	}
	if(ans > sum){
		return true;
	}
	for(int i = 1; i <= sum; i++){
		if(a[i] > asn[i]){
			return false;
		}
	}
	return true;
}


void dfs(int d, int rest){
	if((rest <= 7)&&(rest >= 2)){
		if((d == 1)&&(rest == 6)){
			a[d] = 6;
			sum = 1;
			if(cvb()){
				for(int i = 1; i <= sum; i++){
					asn[i] = a[i];
				}
				for(int i = sum+1; i <= ans; i++){
					asn[i] = 0;
				}
				ans = sum;
			}
			return;
		}
		a[d] = yu[rest];
		sum = d;
		if(cvb()){
			for(int i = 1; i <= sum; i++){
				asn[i] = a[i];
			}
			for(int i = sum+1; i <= ans; i++){
				asn[i] = 0;
			}
			ans = sum;
		}
		return;
	}
	if(rest == 8){
		if(d == 1){//1
			a[d] = 1;
			a[d+1] = 0;
			sum = 2;
			if(cvb()){
				for(int i = 1; i <= sum; i++){
					asn[i] = a[i];
				}
				for(int i = sum+1; i <= ans; i++){
					asn[i] = 0;
				}
				ans = sum;
			}
			return;
		}//1
		a[d] = 0;
		a[d+1] = 1;
		sum = d+1;
		if(cvb()){
			for(int i = 1; i <= sum; i++){
				asn[i] = a[i];
			}
			for(int i = sum+1; i <= ans; i++){
				asn[i] = 0;
			}
			ans = sum;
		}
		return;
	}
	for(int i = 2; i <= 7; i++){
		if((d != 1)||(i != 6)){
			a[d] = yu[i];
			dfs(d+1, rest-i);
		}
	}
	return;
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int p = 0; p < t; p++){
		ans = 100005;
		cin >> n;
		if(n < 2){
			cout << "-1" << endl;
		}
		else if(n%7 == 0){
			for(int i = 1; i <= (n/7); i++){
				cout << "8";
			}
			cout << endl;
		}
		else if(n%7 == 1){
			cout << "20";
			for(int i = 1; i <= ((n-8)/7); i++){
				cout << "8";
			}
			cout << endl;
		}
		else{
			dfs(1, n);
			for(int i = 1; i <= ans; i++){
				cout << asn[i];
				asn[i] = 0;
			}
			cout << endl;
		}
	}
	return 0;
} 
