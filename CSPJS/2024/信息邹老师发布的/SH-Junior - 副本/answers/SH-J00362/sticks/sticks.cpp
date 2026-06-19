#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		if(n%7==0){
			if(n==0){
				cout << -1 << endl;
				continue;
			}
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==1){
			if(n==1){
				cout << -1 << endl;
				continue;
			}
			n-=8;
			cout << 10;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==2){
			n-=2;
			cout << 1;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==3){
			if(n==3){
				cout << 7 << endl;
				continue;
			}
			n-=10;
			cout << 22;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==4){
			if(n==4){
				cout << 4 << endl;
				continue;
			}
			n-=11;
			cout << 20;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==5){
			n-=5;
			cout << 2;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if(n%7==6){
			if(n==6){
				cout << 6 << endl;
				continue;
			}
			n-=13;
			cout << 80;
			n/=7;
			while(n--){
				cout << 8;
			}
			cout << endl;
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
