#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int N,M,A[105],B[105];

bool Cmp(int X,int Y){
	return X > Y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i = 1;i <= N * M;i++){
			scanf("%d",&A[i]);
			B[i] = A[i];
	}
	sort(B + 1,B + N * M + 1,Cmp);
	for (int i = 1;i <= M;i++){
		if (i % 2 == 1){
			for (int j = 1;j <= N;j++){
				if (B[(i - 1) * N + j] == A[1]){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for (int j = N;j >= 1;j--){
				if (B[i * N - j + 1] == A[1]){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
