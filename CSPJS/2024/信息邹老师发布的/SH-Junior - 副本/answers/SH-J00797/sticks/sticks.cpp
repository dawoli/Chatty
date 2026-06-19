#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
int P;
int forcnt,i,j;

void push(int i){
	printf("%d",i);
	return;
}

int n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&P);
	f(forcnt,0,P){
		scanf("%d",&n);
		if(n<=1){
			cout<<-1;
		}else switch(n%7){
			case 0:
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 1:
				push(1);n-=2;
				push(0);n-=6;
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 2:
				push(1);n-=2;
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 3:
				if(n == 3){
					push(7);n-=3;
					break;
				}else if(n == 10){
					push(2);push(2);n-=10;
					break;
				}
				push(2);n-=5;
				push(0);n-=6;
				push(0);n-=6;
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 4:
				if(n == 4){
					push(4);n-=4;
					break;
				}
				push(2);n-=5;
				push(0);n-=6;
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 5:
				n-=5;
				push(2);
				while(n>0){
					n-=7;
					push(8);
				}
				break;
			case 6:
				if(n==6){
					push(6);n-=6;
					break;
				}
				i = 0;
				while(n>0){
					i+=1;
					if(i == 2){
						n-=6;
						push(0);
					}else{
						n-=7;
						push(8);
					}
				}
				break;
		}
		cout<<endl;
	}
	return 0;
}
