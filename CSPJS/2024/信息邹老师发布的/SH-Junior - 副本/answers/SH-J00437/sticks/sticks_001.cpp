#include<bits/stdc++.h>
using namespace std;
#define N 100010

int t,n;
int ans[N];
int num[11] = {6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	memset(ans,0x3f,sizeof(ans));
	
	int ret = 0;
	for(int i = 0;i <= 10888888;i++){//n = 50
		int tmp = i;
		ret = 0;
		while(tmp){
			ret += num[tmp % 10];
			tmp /= 10;
		}
		if(ret >= N){
			continue;
		}
		ans[ret] = min(ans[ret],i);
	}
	for(int i = 0;i < N;i++){
		if(ans[i] == 0x3f3f3f3f){
			ans[i] = -1;
		}
	}
	
	while(t--){
		scanf("%d",&n);
		if(n % 7 == 0 && n >= 7){//specialA 
			for(int i = 0;i < n / 7;i++){
				printf("8");
			}	
		}
		else if(n % 7 == 1 && n >= 8){//specialB
			printf("10");
			for(int i = 1;i < n / 7;i++){
				printf("8");
			}
		}
		else{//n <= 50
			printf("%d",ans[n]);
		}
		printf("\n");
	}
	return 0;
}
