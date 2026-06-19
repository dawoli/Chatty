#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = 0;
	int a,b,c;
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	cin >> a >> b >> c;
	if(a>=b+c || b >= a+c || c >= a+b){
		cout << 0;
	}else{
		cout << 1;
	}
	
	return 0;
}
