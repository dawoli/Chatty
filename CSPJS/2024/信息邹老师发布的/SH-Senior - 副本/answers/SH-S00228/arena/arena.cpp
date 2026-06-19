#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+2;
int n;
int A[maxn];
int ans;

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out","w",stdout);
	
	
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &A[i]);
	}
	sort(A, A+n);
	for(int i=1;i<n;i++){
		if(A[i] == A[i-1]) ans++;
	}
	printf("%d", ans);
	
	return 0;
} 
