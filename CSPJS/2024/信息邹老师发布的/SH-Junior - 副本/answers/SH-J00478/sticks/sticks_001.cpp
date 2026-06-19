#include <bits/stdc++.h>
using namespace std;

int T, n;
int digit;
int highstick, shighstick;
int highdigit, shighdigit;
int minhighdigit, minshighdigit;
int sticknum[8] = {0, 0, 1, 7, 4, 2, 6, 8};
int two[7] = {10,18,22,20,28,68,88};
int amount[8] = {0, 0, 1, 1, 1, 3, 2, 1};
int cnt;
int ans = 0;

int main( ){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	for (int i = 0; i < T; i++){
		cin>>n;
		ans = 0;
		if (n <= 7 and n >= 2){
			ans = sticknum[n];
			cout<<ans;
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (n < 2){
			ans = -1;
			cout<<ans;
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (n > 7 and n <= 14){
			ans = two[n - 8];
			cout<<ans;
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		digit = n / 7 + 1;
		highstick = n % 7;
		if (highstick == 0){
			cnt = 1;
			for (int j = 1; j <= digit - 1; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (highstick == 2 or highstick == 5){
			cnt = 1;
			cout<<sticknum[highstick];
			for (int j = 1; j <= digit - 1; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		
		if (highstick == 6){
			cnt = 1;
			cout<<sticknum[highstick];
			for (int j = 1; j <= digit - 1; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (highstick == 3){
			cnt = 1;
			cout<<2;
			cout<<0;
			cout<<0;
			for (int j = 1; j <= digit - 3; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (highstick == 4){
			cnt = 1;
			cout<<2;
			cout<<0;
			for (int j = 1; j <= digit - 2; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
		if (highstick == 1){
			cnt = 1;
			cout<<1;
			cout<<0;
			for (int j = 1; j <= digit - 2; j++){
				cout<<8;
			}
			if (i != T - 1){
				cout<<"\n";
			}
			continue;
		}
	}
	return 0;
}
