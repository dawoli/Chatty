#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(!n%7){
			int m = n/7;
			for(int i = 1; i <= m; i++)cout << 8;
			cout << endl;
			break; 
		}
		int m = n/7, k = n%7;
		if(m>0){
			if(k==1){
			cout << 10;
			
			}else if(k==2){
			cout << 18;
			}else if(k==3){
				cout << 40;
				
			}else if(k==4){
				cout << 20;
				
			}else if(k==5){
				cout << 28;
			}else if(k==6){
				cout << 68;
			}
		}else{
			if(k==1)cout << -1;
			if(k==2)cout << 1;
			if(k==3)cout << 7;
			if(k==4)cout << 4;
			if(k==5)cout << 2;
			if(k==6)cout << 6;
		}
		for(int i = 1; i < m; i++)cout << 8;
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
