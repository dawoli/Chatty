#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	scanf("%d",&n);
	int md = n % 7;
	int n8 = n / 7;
	if(n8 == 0){
		if(n == 1) printf("-1\n");
		else if(n == 2) printf("1\n");
		else if(n == 3) printf("7\n");
		else if(n == 4) printf("4\n");
		else if(n == 5) printf("2\n");
		else if(n == 6) printf("6\n");
		else assert(false);
		return;
	}
	n8--;
	switch(md){
		case 0:
			n8++;
			break;
		case 1:
			printf("10");
			break;
		case 2:
			printf("18");
			break;
		case 3:
			printf("22");
			break;
		case 4:
			printf("20");
			break;
		case 5:
			printf("28");
			break;
		case 6:
			printf("68");
			break;
		default:assert(false);
	}
	for(int i = 1;i <= n8;i++){
		printf("8");
	}
	printf("\n");
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
