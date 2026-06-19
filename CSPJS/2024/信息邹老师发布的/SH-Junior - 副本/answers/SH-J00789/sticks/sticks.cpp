#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	int g[] = {};
	cin >> T;
	for(int i = 0;i < T;i ++){
		int n;
		cin >> n;
		if(n == 1) cout << -1;
		else{
			long long a = 1,count = 0;
			while (1){
				int s = 0;
				long long b = a;
				while (1){
					if(a >=2100000000) cout << -1;
					else if(a % 10 == 0 || a % 10 == 6 || a % 10 == 9) count += 6;
					else if(a % 10 == 1) count += 2;
					else if(a % 10 == 2 || a % 10 == 3 || a % 10 == 5) count += 5;
					else if(a % 10 == 4) count += 4;
					else if(a % 10 == 7) count += 3;
					else if(a % 10 == 8) count += 7;
					if(count == n){
						cout << b;
						s = 1;
						break;
					}
					else if(a == 0) break;
					else a /= 10;
				}
				if(s) break;
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
