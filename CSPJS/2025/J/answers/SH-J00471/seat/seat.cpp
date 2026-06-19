#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int aList[109];
	for (int i = 0; i < n*m; i ++){
		cin >> aList[i];
	}
	int rScore = aList[0];
	int flag = 1;
	while (flag == 1){
		flag = 0;
		for (int i = 0; i < n * m - 1; i ++){
			if (aList[i] < aList[i+1]){
				int t = aList[i];
				aList[i] = aList[i + 1];
				aList[i+1] = t;
				flag = 1;
			}
		}
	}
	int No = 0;
	for (; No < n*m; No ++){
		//cout << aList[No];
		if (aList[No] == rScore) break;
	}
	int x, y;
	if (No % (n * 2) < n){
		x = No / n;
		y = No % n;
	}
	else{
		x = No / n + 1;
		y = n - No % n;
	}
	x ++;
	y ++;
	cout << x << " " << y;
	return 0;
}

