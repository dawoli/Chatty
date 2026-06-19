#include <bits/stdc++.h>
using namespace std;
int t,n,m;
void fun(int n){
	if (n==1) cout << "-1" << endl;
	else if (n==2) cout << 1 << endl;
	else if (n==3) cout << 7 << endl;
	else if (n==4) cout << 4 << endl;
	else if (n==5) cout << 2 << endl;
	else if (n==6) cout << 6 << endl;
	else if (n==7) cout << 8 << endl;
	return;
}
void fun1(){
	for (int j=1;j<=m-2;j++){
		cout << 8;
	}
	cout << endl;
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for (int i=1;i<=t;i++){
		cin >> n;
		if (n<=7){
			fun(n);
			continue;
		}
		m=ceil(n/7.0);
		if (n%7==0){
			for (int j=1;j<=m;j++){
				cout << 8;
			}
			cout << endl;
		}else if (n%7==1){
			cout << 10;
			fun1();
		}else if (n%7==2){
			cout << 18;
			fun1();
		}else if (n%7==3){
			cout << 22;
			fun1();
		}else if (n%7==4){
			cout << 20;
			fun1();
		}else if (n%7==5){
			cout << 28;
			fun1();
		}else if (n%7==6){
			cout << 68;
			fun1();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
