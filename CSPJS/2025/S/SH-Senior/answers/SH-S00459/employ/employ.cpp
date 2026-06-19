#include<bits/stdc++.h>
using namespace std;
long long N, M;
string sList;
int cList[500];

long long aaaaa(long long n){
	long long ans = 1;
	for (long long i = n; i >0; i --)
		ans *= i;
	return ans;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> N >> M;
	
	bool flag = 0;
	for (int i = 0; i < N; i ++){
		cin >> cList[i];
		if (dList[i] != 0)
			flag = 1;
	}
	if (flag == 0){
		cout << 0;
		return 0;
	}
	cout << aaaaa(N) / aaaaa(M);
	return 0;
}

