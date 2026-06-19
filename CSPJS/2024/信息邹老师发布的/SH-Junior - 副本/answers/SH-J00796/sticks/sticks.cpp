#include<bits/stdc++.h>
using namespace std;
string mn = "";
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T, n;
	cin >> T;
	while(T--){
		mn = "";
		cin >> n;
		if(n <= 1){
			cout << -1 << endl;
			continue;
		}
		if(n == 3){
			cout << 7 << endl;
			continue;
		}
		if(n % 7 == 0)
			for(int i = n / 7; i > 0; --i)
				mn += '8';
		else if(n % 7 == 1){
			mn = "10";
			for(int i = n / 7 - 1; i > 0; --i)
				mn += '8';
		}
		else if(n % 7 == 2){
			mn = "1";
			for(int i = n / 7; i > 0; --i)
				mn += '8';
		}
		else if(n % 7 == 3){
			mn = "22";
			for(int i = n / 7 - 1; i > 0; --i)
				mn += '8';
		}
		else if(n % 7 == 4){
			mn = "4";
			for(int i = n / 7; i > 0; --i)
				mn += '8';
		}
		else if(n % 7 == 5){
			mn = "2";
			for(int i = n / 7; i > 0; --i)
				mn += '8';
		}
		else if(n % 7 == 6){
			mn = "6";
			for(int i = n / 7; i > 0; --i)
				mn += '8';
		}
		if(mn != "")
			cout << mn << endl;
		else
			cout << -1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

