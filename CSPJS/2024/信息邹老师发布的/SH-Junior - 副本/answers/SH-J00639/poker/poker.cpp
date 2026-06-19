#include<bits/stdc++.h>

using namespace std;

char q[5], qwq[5] = {'D', 'C', 'H', 'S'}, awa[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int n, a[5][14], z_1, z_2, sum; 

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> q;
		for(int j = 0; j < 4; j++){
			if(q[0] == qwq[j]){
				z_1 = j;
			}
		}
		for(int j = 0; j < 13; j++){
			if(q[1] == awa[j]){
				z_2 = j;
			}
		}
		if(a[z_1][z_2] != 1){
			sum++;
			a[z_1][z_2] = 1;
		}
	}
	sum = 52-sum;
	cout << sum;
	return 0;
} 
