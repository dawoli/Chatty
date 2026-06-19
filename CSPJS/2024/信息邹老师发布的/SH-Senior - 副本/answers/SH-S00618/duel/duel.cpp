#include<bits/stdc++.h>
using namespace std;
int N,R[100005],sum;
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		int A;
		scanf("%d",&A);
		R[A]++;
	}
	sum=R[1];
	for(int i=2;i<=100000;i++) {
		sum=max(sum,R[i]);
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
