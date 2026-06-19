#include<bits/stdc++.h>
using namespace std;
int T,N;
long long F[300][300][300];
long long A[1000000],B[1000000],C[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>N;
	    int Limit=N/2;
		long long Ans=0;
		bool f=1;
		memset(F,0,sizeof(F));
		for(int i=1;i<=N;i++) cin>>A[i]>>B[i]>>C[i];
		for(int i=1;i<=N;i++){
			if(B[i]!=0||C[i]!=0) f=0;
		}
		if(f){
			sort(A+1,A+N+1);
			for(int i=N;i>N/2;i--) Ans+=A[i];
			printf("%d\n",Ans);
			continue;
		}
		for(int i=1;i<=N;i++){
			for(int j=Limit;j>=0;j--){
				for(int k=Limit;k>=0;k--){
					for(int l=Limit;l>=0;l--){
						F[j+1][k][l]=max(F[j+1][k][l],F[j][k][l]+A[i]);
						F[j][k+1][l]=max(F[j][k+1][l],F[j][k][l]+B[i]);
						F[j][k][l+1]=max(F[j][k][l+1],F[j][k][l]+C[i]);
					}
				}
			}
		}
		for(int i=0;i<=Limit;i++){
			for(int j=0;j<=Limit;j++){
				for(int k=0;k<=Limit;k++){
					Ans=max(F[i][j][k],Ans);
				}
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
