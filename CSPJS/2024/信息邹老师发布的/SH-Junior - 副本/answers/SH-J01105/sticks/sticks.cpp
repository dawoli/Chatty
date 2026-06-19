#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int T=0;T<t;T++){
		int n;
		scanf("%d",&n);
		if(n<2){
			printf("-1\n");
			continue;
		}
		else if(n==2){
			printf("1\n");
			continue;
		}
		else if(n==3){
			printf("7\n");
			continue;
		}
		else if(n==4){
			printf("4\n");
			continue;
		}
		else if(n==5){
			printf("2\n");
			continue;
		}
		else if(n==6){
			printf("6\n");
			continue;
		}
		int rest=n;
		int num[10]={0,0,0,0,0,0,0,0,0,0};
		num[8] = n/7;
		rest = n%7;
		if(rest!=0){
			num[8]--;
			if(rest==1){
				num[1]++;
				num[0]++;
			}
			else if(rest==2){
				num[7]++;
				num[0]++;
			}
			else if(rest==3){
				num[4]++;
				num[0]++;
			}
			else if(rest==4){
				num[2]++;
				num[0]++;
			}
			else if(rest==5){
				num[0]++;
				num[0]++;
			}
			else{
				num[8]++;
				num[0]++;
			}
		}
		for(int i=1;i<=9;i++){
			if(num[i]>0){
				printf("%d",i);
				num[i]--;
				break;
			}
		}
		for(int i=0;i<=9;i++){
			for(int j=0;j<num[i];j++){
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}

