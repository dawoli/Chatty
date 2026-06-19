#include <bits/stdc++.h>
using namespace std;
void f(){
	int n,digit;
	cin >> n;
	if (n%7==0){
		digit = n/7;
		for (int i=1;i<=digit;i++){
			cout << "8";
		}
		cout << endl;
	}
	else if (n%7==1){
		if (n==1){
			cout << "-1";
		}
		else{
			cout << "10";
			digit = (n-8)/7;
			for (int i=1;i<=digit;i++){
				cout << "8";
			}
		}
		cout << endl;
	}
	else if (n%7==2){
		cout << "1";
		digit = (n-2)/7;
		for (int i=1;i<=digit;i++){
			cout << "8";
		}
		cout << endl;
	}
	else if (n%7==3){
		if (n==3){
			cout << "7";
		}
		else if (n==10){
			cout << "22";
		}
		else{
			cout << "200";
			digit = (n-17)/7;
			for (int i=1;i<=digit;i++){
				cout << "8";
			}
		}
		cout << endl;
	}
	else if (n%7==4){
		if (n==4){
			cout << "4";
		}
		else{
			cout << "20";
			digit = (n-11)/7;
			for (int i=1;i<=digit;i++){
				cout << "8";
			}
		}
		cout << endl;
	}
	else if (n%7==5){
		cout << "2";
		digit = (n-5)/7;
		for (int i=1;i<=digit;i++){
			cout << "8";
		}
		cout << endl;
	}
	else if (n%7==6){
		cout << "6";
		digit = (n-6)/7;
		for (int i=1;i<=digit;i++){
			cout << "8";
		}
		cout << endl;
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while (T){
		f();
		T--;
	}
	return 0;
}
