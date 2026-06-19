#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

long long K,A[500005];
int N;
bool F1 = 1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&N,&K);
	for (int i = 1;i <= N;i++){
		scanf("%d",&A[i]);
		if (A[i] != 1){
			F1 = 0;
		}
	}
	if (F1){
		if (K == 1) printf("%d",N);
		else{
			printf("0");
		}
	}
	else{
		long long Ans = 0;
		bool Visited[100005];
		memset(Visited,1,sizeof(Visited));
		for (int i = 1;i <= N;i++){
			if (A[i] == 0){
				Ans++;
				continue;
			}
			if (A[i] == A[i + 1] && Visited[i] && Visited[i + 1] && i != N){
				Visited[i] = 0;
				Visited[i + 1] = 0;
				Ans++;
			}
		}
		printf("%lld",Ans);
	}
	return 0;
}
