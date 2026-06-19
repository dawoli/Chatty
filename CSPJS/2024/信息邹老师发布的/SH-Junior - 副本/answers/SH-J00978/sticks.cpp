#include<bits/stdc++.h>
using namespace std;
long long T,n;
const int x[] = {0,0,1,7,4,2,0,8};
const int y[] = {6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> n;
		if(n == 1){
			cout << "-1" << endl;
			continue;
		}else if(n % 7 == 0){
			for(int j = n;j > 0;j -= 7) cout << "8";
			cout << endl;
		}else if(n % 7 == 1){
			cout << "10";
			for(int j = n-8;j > 0;j -= 7) cout << "8";
			cout << endl;
		}
	}
	return 0;
}
