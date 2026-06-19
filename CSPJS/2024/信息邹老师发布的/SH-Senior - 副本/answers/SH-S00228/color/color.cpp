#include<bits/stdc++.h>
using namespace std;

const int maxn=2e3+2;
int A[maxn];
//int dp[maxn][maxn];
int T, n;
int ans=0;

int calc(__int128 x){ //(l, r)
	int res=0;
	for(int i=0;i<n;i++){
		if(((1<<i) & x) != 0){
			for(int j=i+1;j<n;j++){
				if(((1<<j) & x) != 0 && A[i] == A[j]) res+=A[i];
			}
		}
	}
	for(int i=0;i<n;i++){
		if(((1<<i) & x) == 0){
			for(int j=i+1;j<n;j++){
				if(((1<<j) & x) == 0 && A[i] == A[j]) res+=A[i];
			}
		}
	}
	return res;
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out","w",stdout);
	
	
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%d", &A[i]);
		}
		for(__int128 i=0;i<=(1<<n)-1;i++){//0:red 1:blue
			ans=max(ans, calc(i));
		}
		printf("%d\n", ans);
	}
		
	
	return 0;
} 
