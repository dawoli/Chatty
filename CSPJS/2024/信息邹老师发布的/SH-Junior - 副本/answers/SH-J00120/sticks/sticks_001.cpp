#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int f=0;
		if(n<2){
			cout << -1 << endl;
			continue;
		}
		while(n>6){
			int o=n%7;
			if(o==0){
				cout << 8;
				n-=7;
			}else{
				if(f==1){
					cout << 0;
					n-=6;
				}else{
					if(o<3){
						cout << 1;
						n-=2;
					}else if(o<6){
						cout << 2;
						n-=5;
					}
					if(o==6){
						cout << 6;
						n-=6;
					}
				}
			}
			f=1;
		}
		if(n==2) cout << 1;
		else if(n==3) cout << 7;
		else if(n==4) cout << 4;
		else if(n==5) cout << 2;
		else if(n==6&&f==1) cout << 0;
		else if(n==6&&f==0) cout << 6;
		cout << endl;
	}
	return 0;
}
