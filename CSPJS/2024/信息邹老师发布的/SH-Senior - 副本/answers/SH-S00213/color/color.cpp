#include<bits/stdc++.h>
using namespace std;

int T;

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout); 
	scanf("%d", &T);
	for(int i=1;i<=T;i++){
		int n,ans=0;
		scanf("%d", &n);
		int A[200002];
		for(int j=1;j<=n;j++)
			scanf("%d", &A[j]);
		sort(A+1,A+n+1);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(A[i]==A[j]){
					ans+=A[i];
					break;
				}
		printf("%d\n", ans);
	}
	return 0;
}
