#include<bits/stdc++.h>
using namespace std;

int T;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n==1){
			putchar('-');putchar('1');
		}else if(n==3){
			putchar('7');
		}else if(n==4){
			putchar('4');
		}else if(n%7==1){
			putchar('1');putchar('0');n-=8;
		}else if(n%7==2){
			putchar('1');n-=2;
		}else if(n%7==3){
			putchar('2');putchar('3');n-=10;
		}else if(n%7==4){
			putchar('2');putchar('0');n-=11;
		}else if(n%7==5){
			putchar('2');n-=5;
		}else if(n%7==6){
			putchar('6');n-=6;
		}
		for(int i=1;i<=n/7;i++)putchar('8');
		putchar('\n');
	}
	return 0;
}
