#include<bits/stdc++.h>
using namespace std;
int test,n,k,cnt=0,ans[100001];
char s[15000];
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&test);
	for(;test--;){
		scanf("%d",&n);
		k=n/7;
		if(n%7==0){
			for(int i=1;i<=k;i++){
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
