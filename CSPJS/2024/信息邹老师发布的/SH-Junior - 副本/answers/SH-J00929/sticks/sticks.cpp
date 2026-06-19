#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n,o=0,a[11]={6,2,5,5,4,5,6,3,7,0};
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		int q=0;
		scanf("%d",&n);
		int w = (n-1)/7 + 1;
		if(n%7==0){
			for(int i=1;i<=w;i++){
				printf("8");
			}
			printf("\n");
			continue;
		}
		if(w==1){
			for(int i=1;i<=8;i++){
				if(n==a[i]){
					printf("%d\n",i);
					q=1;
					o=1;
					break;
				}
			}
			if(q==0){
				printf("-1\n");
			}
		}
	}
	if(o==1){
		printf("208");
	}
	return 0;
}
