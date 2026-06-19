#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool Cmp(int X,int Y){
	return X > Y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string S;
	int A[15];
	memset(A,0,sizeof(A));
	cin >> S;
	int N = S.size();
	for (int i = 0;i < N;i++){
		char C = char(S[i]);
		if ('0' <= C && C <= '9'){
			int Tmp = int(C) - 48;
			A[Tmp]++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= A[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
