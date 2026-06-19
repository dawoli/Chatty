#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll st[11]={6,2,5,5,4,5,6,3,7,6},t,n,qi,yi,le;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		if (n<2){
			cout << -1 << endl;
			continue;
		}
		if (n==2){
			cout << 1 << endl;
			continue;
		}
		if (n==3){
			cout << 7<<endl;
			continue;
		}
		if (n==4){
			cout << 4<<endl;
			continue;
		}
		if (n==5){
			cout << 2<<endl;
			continue;
		}
		if (n==6){
			cout << 6<<endl;
			continue;
		}
		if (n==7){
			cout << 8<<endl;
			continue;
		}
		if (n==8){
			cout << 10<<endl;
			continue;
		}
		qi=n/7;
		n-=qi*7;
		if (n==6){
			cout << 68;
			qi--;
		}
		if (n==5){
			cout << 17;
		}
		if (n==4){
			cout << 20;
			qi--;
		}
		if (n==3){
			cout << 7;
		}
		if (n==2){
			cout << 1;
		}
		if (n==1){
			cout << 10;
			qi--;
		}
		for (int i=0;i<qi;i++){
			cout << 8;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
