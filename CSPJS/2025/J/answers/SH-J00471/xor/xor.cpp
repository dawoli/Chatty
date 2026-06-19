#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int N, K;
	int aList[100009];
	int rList[100009];
	cin >> N >> K;
	for(int i = 0;i < N; i ++){
		cin >> aList[i];
	}
	int sum = N;
	for (int i = 0; i < N*(N+1)/2; i ++){
		rList[i] = 0;
		int no = i - (N-sum+1) * (N-sum)/2;
		for (int x = 0; x < sum; x ++){
			rList[i] = rList[i] ^ aList[no+x];
		}
		//cout << rList[i] << ' ';
		if (no == N-sum){
			//cout << endl;
			sum --;
		}
	}
	
	int line =N*(N+1)/2 - N - 1, lineIndex = N - 1;
	bool flag[100009];
	memset(flag, 0, sizeof(flag));
	int cnt = 0;
	for (int i = N*(N+1)/2 - 1; i >= 0; i --){
		if (i == line){
			line -= lineIndex;
			lineIndex--;
		}
		if (flag[i] == 1) {
			flag[i - lineIndex - 1] = 1;
			if (i - lineIndex  <= line){
				flag[i - lineIndex] =1;
			}
			continue;
		}
		if (rList[i] == K){
			cnt ++;
			flag[i - lineIndex - 1] = 1;
			if (i - lineIndex  <= line){
				flag[i - lineIndex] =1;
			}
		}
	}
	cout << cnt;
	return 0;
}

