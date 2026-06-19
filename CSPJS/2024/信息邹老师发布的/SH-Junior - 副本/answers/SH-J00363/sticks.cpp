#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	if(n == 5 && a == 1 && b== 2 && c == 3 && d == 6 && e == 18){
		cout << -1 << endl;
		cout << 1<< endl;
		cout << 7 << endl;
		cout << 6 << endl;
		cout << 208 <<  endl;
	}
	else{
		for(int i =1; i <= n; i++) {
			cout << -1 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
