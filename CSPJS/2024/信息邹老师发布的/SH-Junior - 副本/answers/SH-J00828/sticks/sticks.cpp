#include<bits/stdc++.h>
using namespace std;
int n;
int st[1005]= {6,2,5,5,4,5,6,3,7,6};
void dA(int k) {
	for(int i=1;i<=k/7;i++){
		cout <<"8";
	}
	cout << endl;
}
void dB(int k) {
	cout <<"10";
	for(int i=1;i<=(k-8)/7;i++){
		cout << "8";
	}
	cout << endl;
}
void dd(int a){
	if(a==2){
		cout << "1";
		dA(n-2);
	}
	if(a==3){
		cout << "22";
		dA(n-10);
	}
	if(a==4){
		cout << "20";
		dA(n-11);
	}
	if(a==5){
		cout <<"60";
		dA(n-12); 
	}
	if(a==6){
		cout << "80";
		dA(n-13);
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin >> T;
	while(T--) {

		cin >> n;
		if(n==1){
			cout << -1<<endl;
			continue;
		}
		if(n==2){
			cout << 1<<endl;
			continue;
		}
		if(n==3){
			cout << 7<<endl;
			continue;
		}
		if(n==4){
			cout << 4<<endl;
			continue;
		}
		if(n==5){
			cout << 2<<endl;
			continue;
		}
		if(n==6){
			cout << 6<<endl;
			continue;
		}
		
		if(n%7==0) {
			dA(n);
		}else if(n%7==1){
			dB(n);
		}else{
			dd(n%7);
		}
	}
}
