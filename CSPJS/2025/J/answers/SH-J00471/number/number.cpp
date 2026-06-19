#include<bits/stdc++.h>
using namespace std;
char sList[1000000];
int nList[1000000];
long long ans = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	int i = 0;
	while (cin >> sList[i]){
		if ('0' <= sList[i] && sList[i] <= '9'){
			nList[cnt] = sList[i];
			nList[cnt] -= 48;
			cnt ++;
		}
		i ++;
	}
	//cout << nList[0];
	for (int n = 9; n >= 0; n --){
		int numNum = 0;
		for (int i = 0; i < cnt; i ++){
			if (nList[i] == n){
				numNum ++;
			}
		}
		for (int i = 0; i < numNum; i ++){
			cout << n;
		}
	}
	
	return 0;
}

