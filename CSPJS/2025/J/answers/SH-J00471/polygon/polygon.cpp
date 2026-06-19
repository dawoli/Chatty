#include<bits/stdc++.h>
using namespace std;
int N;
int rList[50009];
bool is_ok(int select){
	int  nMax = -1, sum = 0;
	for (int i = 0; i < N; i ++){
		if ((select >> i) % 2 == 1){
			if (rList[i] > nMax){
				nMax = rList[i];
			}
			sum += rList[i];
		}
	}
	if (sum > 2*nMax){
		return 1;
	}
	return 0;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> N;
	//if (N < 20){
		for (int i = 0; i < N; i ++){
			cin >> rList[i];
		}
		int choice = 1;
		for (int i = 0; i < N; i ++){
			choice *= 2;
		}
		unsigned long long cnt = 0;
		//cout << choice << endl;
	
		for (int i = 1; i < choice; i ++){
			if (is_ok(i)){
				//cout << cnt +1 <<endl;
				cnt ++;
			}
		}
		cout << cnt;
//	}
	
	return 0;
}

