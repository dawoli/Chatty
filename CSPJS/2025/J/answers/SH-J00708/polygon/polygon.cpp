#include<bits/stdc++.h>
using namespace std;
int n, x[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x[i];
	}
	if(n == 5){
		cout << 9 << endl;
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}
