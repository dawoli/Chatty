#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int o = 1;o <= t;o++){
		cin >> n;
		int x = n / 7,y = n % 7;string s = "";
		if(y == 1){
			if(x) x--,s = "20";
			else s = "-1";
		}
		if(y == 2) s = "1";
		if(y == 3){
			if(x) s = "22",x--;
			else s = "7";
		}
		if(y == 4){
			if(x) s = "20",x--;
			else s = "4";
		}
		if(y == 5) s = "2";
		if(y == 6) s = "6";
		cout << s;
		for(int i = 1;i <= x;i++) cout << 8;
		cout << endl;
	}
	return 0;
}
