#include<bits/stdc++.h>
using namespace std;
int t[20] = {0,0,1,7,4,2,6,8,10,18,22,20};
int n,cnt;
int x;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&x);
		if(x == 1){
			printf("-1\n");
			continue;
		}
		cnt = 0;
		while(x > 11){
			cnt++;
			x -= 7;
		}
		printf("%d",t[x]);
		for(int j = 1;j <= cnt;j++){
			printf("8");
		}
		printf("\n");
	}
	return 0;
} 
