#include <bits/stdc++.h>

int A[1000001];
bool isred(int index,unsigned long long i){
	return (i>>index)%2==0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]); 
		}
		int C=0;
		if(n<=15){
			for(unsigned long long i=0;i<1ULL<<n;i++){
				int c=0;
				for(int j=1;j<n;j++){
					for(int k=j-1;k>=0;k--){
						if(isred(j,i)==isred(k,i)){
							if(A[j]==A[k]) c+=A[j];
							break;
						}
					}
				}
				if(c>C) C=c;
	//			printf("Calced: %ull All: %ull\n",i,1ULL<<n);
			}
		}
		else{
			for(int j=0;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(A[j]==A[k]) {
						C+=A[j];
						A[k]=-1-k;
						break;
					}
				}
			}
		}
		printf("%d\n",C); 
	}
	return 0;
}
