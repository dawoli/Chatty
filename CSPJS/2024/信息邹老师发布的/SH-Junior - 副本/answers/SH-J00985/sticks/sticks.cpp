#include<bits/stdc++.h>
using namespace std;
int t,goal;
void fun(int goal){
	if (goal==1){
		printf("-1\n");
		return;
	}
	if (goal==3){
		printf("7\n");
		return;
	}
	if (goal==4){
		printf("4\n");
		return;
	}
	if (goal==6){
		printf("6\n");
		return;
	}
	if (goal%7==0){
		int n=goal/7;
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal==8){
		printf("10\n");
		return;
	}
	if (goal%7==1){
		int n=goal/7-1;
		printf("10");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal%7==2){
		int n=goal/7;
		printf("1");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal%7==3){
		int n=goal/7-1;
		printf("22");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal%7==4){
		int n=goal/7-1;
		printf("20");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal%7==5){
		int n=goal/7;
		printf("2");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
	if (goal%7==6){
		int n=goal/7;
		printf("6");
		for(int i=0;i<n;i++){
			printf("8");
		}
		printf("\n");
		return;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&goal);
		fun(goal);
	}
	return 0;
}
