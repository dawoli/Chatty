#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int N,Sum = 0,Maxn = 0,A[5005];

long long Jc(int N,int M){
	long long Ans = 1;
	if (M > N / 2){
		M = N - M;
	}
	for (int i = 0;i < M;i++){
		Ans = Ans * (N - i);
	}
	return Ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&N);
	if (N == 3){
		for (int i = 1;i <= N;i++){
			scanf("%d",&A[i]);
			Sum += A[i];
			Maxn = max(Maxn,A[i]);
		}
		if (Sum > Maxn * 2){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else if (N < 3){
		printf("0");
	}
	else{
		for (int i = 1;i <= N;i++){
			scanf("%d",&A[i]);
		}
		long long Ans = 0;
		for (int i = 3;i <= N;i++){
			Ans = (Ans + Jc(N,i)) % 998244353;
		}
		printf("%lld",Ans);
	}
	return 0;
}
