#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int cnt[10] = {6,2,5,5,4,5,6,3,7,6};
const int N = 1e5+5;

int main(){
	
	//freopen("sticks.in","w",stdin);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		if (n%7==0){
			if (n == 0) cout << "-1";
			else{
				for (int i = 1;i <= n/7;i++) cout << "8";
			}
			//30;
		}
		else if (n%7==1){
			if (n == 1) cout << "-1";
			else{
				cout << "10";
				for (int i = 1;i <= (n-8)/7;i++) cout << "8";
			}
			//30
		}
		else if (n%7==2){
			cout << "1";
			for (int i = 1;i <= (n-2)/7;i++) cout << "8";
		}
		else if (n%7==3){
			if (n == 3) cout << "7";
			else{
				cout << "22";
				for (int i = 1;i <= (n-10)/7;i++) cout << "8";
			}
		}
		else if (n%7==4){
			if (n == 4) cout << "4";
			else{
				cout << "20";
				for (int i = 1;i <= (n-11)/7;i++) cout << "8";
			}
		}
		else if (n%7==5){
			if (n == 5) cout << "2";
			else{
				cout << "28";
				for (int i = 1;i <= (n-12)/7;i++) cout << "8";
			}
		}
		else if (n%7==6){
			if (n == 6) cout << "6";
			else{
				cout << "80";
				for (int i = 1;i <= (n-13)/7;i++) cout << "8";
			}	
		}
		cout << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
