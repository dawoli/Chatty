#include<bits/stdc++.h>
using namespace std;
int check[14]{-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
void work(int n){
	if(n<7||n==10) {
		cout << check[n] << endl;
		return;
	}
	int k=n/7-1,g=n%7+7;
	if(g!=10){
		cout << check[g];
	}
	else{
		cout << 200;
		k--;
	}
	while(k--)cout<<'8';
	cout << endl;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		work(n);
	}
	return 0;
}
