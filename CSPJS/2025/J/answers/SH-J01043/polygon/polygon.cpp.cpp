#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long a, b, c, n;
	cin >> n;
	cin >> a >> b >>c;
	if(a+b <= c||a+c <= b||b+c <= c){
		cout << 0;
	}
	else{
		cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
