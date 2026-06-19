#include<bits/stdc++.h>
using namespace std;
int t,n;
int mpp[12]={6,2,5,5,4,5,6,3,7,6};
int ans[100005];
void handle(int r){
	if(r==0){
		for(int i=1;i<=n/7;i++)putchar('8');
		putchar('\n');
	}else if(r==1){
		putchar('1');putchar('0');
		for(int i=1;i<=n/7-1;i++)putchar('8');
		putchar('\n');
	}else if(r==2){
		putchar('1');
		for(int i=1;i<=n/7;i++)putchar('8');
		putchar('\n');
	}else if(r==5){
		putchar('2');
		for(int i=1;i<=n/7;i++)putchar('8');
		putchar('\n');
	}else if(r==6){
		putchar('6');
		for(int i=1;i<=n/7;i++)putchar('8');
		putchar('\n');
	}else if(r==3){
		int k=n/7;
		if(k==1){
//			printf("22\n");
			putchar('2');
			putchar('2');
			putchar('\n');
		}else{
//			printf("200");
			putchar('2');
			putchar('0');
			putchar('0');
			for(int i=1;i<=n/7-2;i++)putchar('8');
			putchar('\n');
		}
	}else if(r==4){
		int k=n/7;
//			printf("20");
			putchar('2');
			putchar('0');
			for(int i=1;i<=n/7-1;i++)putchar('8');
			putchar('\n');
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("-1\n");
			continue;
		}else if(n==2){
			printf("1\n");
			continue;
		}else if(n==3){
			printf("7\n");
			continue;
		}else if(n==4){
			printf("4\n");
			continue;
		}else if(n==5){
			printf("2\n");
			continue;
		}else if(n==6){
			printf("6\n");
			continue;
		}else if(n==7){
			printf("8\n");
			continue;
		}
		int r=n%7;
		handle(r);
	}
	return 0;
}
